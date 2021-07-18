BUILDDIR=./build
OUTDIR=./out
SRCDIR=./src

SUBDIRS=\
		.\
		utils\
		dataHandler

LINK_FLAGS=\
			-LOpenSiv3D/lib\
			-LOpenSiv3D/lib/freetype\
			-LOpenSiv3D/lib/harfbuzz\
			-LOpenSiv3D/lib/opencv\
			-lfreetype -lharfbuzz\
			-lopencv_core\
			-lopencv_imgproc\
			-lopencv_objdetect\
			-lopencv_photo\
			-lSiv3D
EM_FLAGS=\
			-O0\
			-std=c++17\
			-g4
HEADER_FLAGS=\
			-Iheaders\
			-IOpenSiv3D/include\
			-IOpenSiv3D/include/ThirdParty

CPP_FILES = $(foreach dir,$(SUBDIRS), $(foreach cpp, $(wildcard $(SRCDIR)/$(dir)/*.cpp), $(cpp)))
OBJ_FILES = $(patsubst $(SRCDIR)%.cpp, $(OUTDIR)%.o, $(CPP_FILES))

all: $(BUILDDIR)/index.html

$(BUILDDIR)/index.html: $(OBJ_FILES)
	em++ $(OBJ_FILES) \
	-o $@ \
	${EM_FLAGS} \
	${LINK_FLAGS} \
	--emrun -s FULL_ES3=1 -s USE_GLFW=3 -s USE_LIBPNG=1 -s USE_OGG=1 -s USE_VORBIS=1 -s ALLOW_MEMORY_GROWTH=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 \
	--preload-file OpenSiv3D/example@/example --preload-file OpenSiv3D/resources@/resources \
	--shell-file template-web-player.html --js-library OpenSiv3D/lib/Siv3D.js

# ディレクトリ名を受け取ってOBJファイルに一括依存させる
# 現状未使用だが、今後何かのために使うかも
define DEPEND_DIR

$(1): $(OUTDIR)/$(1) $(patsubst $(SRCDIR)%.cpp, $(OUTDIR)%.o, $(wildcard $(SRCDIR)/$(1)/*.cpp))
	@echo Compiled sub directory \"$(1)\"
	
$(OUTDIR)/$(1):
	mkdir -p $(OUTDIR)/$(1)

endef

# ,のあとにスペースを入れると正しく展開されない
$(foreach dir, $(SUBDIRS), $(eval $(call DEPEND_DIR,$(dir))))

# 単一のcppファイルについてコンパイルを行う
define COMPILE

$(patsubst $(SRCDIR)%.cpp, $(OUTDIR)%.o, $(1)): $(1)
	@mkdir -p $(dir $(1))
	em++ $(1) -c -o $(patsubst $(SRCDIR)%.cpp, $(OUTDIR)%.o, $(1)) ${EM_FLAGS} ${HEADER_FLAGS}

endef

$(foreach file, $(CPP_FILES), $(eval $(call COMPILE,$(file))))