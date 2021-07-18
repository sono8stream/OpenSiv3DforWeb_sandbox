#include <map>
#include "dataHandler/HumanHandler.h"

using namespace std;

namespace dataWorld
{
    /*
    すべてのデータの窓口を担う
    各ハンドラにイベントリスナを付与する
    */
    class DataWorld
    {
        map<string, dataHandler::HumanHandler> handlers;

    public:
        void setHandler();
    };
}