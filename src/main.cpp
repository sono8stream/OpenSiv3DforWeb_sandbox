#include <Siv3D.hpp>
#include <emscripten.h>

#include "utils/minSono.h"
#include "utils/maxSono.h"

using namespace std;

void Main()
{
    printf("AIUEO2\n");
    int a = 10;
    int b = 100;
    printf("%d\n", minSono(a, b));
    printf("%d\n", maxSono(a, b));

    Platform::Web::System::SetMainLoop([&]()
                                       {
                                           if (!System::Update())
                                           {
                                               ::emscripten_cancel_main_loop();
                                           }
                                       });
}