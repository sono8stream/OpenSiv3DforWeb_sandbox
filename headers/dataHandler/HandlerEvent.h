#pragma once
#include <string>

namespace dataHandler
{
    /*
    ハンドライベント実体
    各ハンドラは一つ一つにリスナーを紐づける
    */

    struct HandlerEvent
    {
        std::string name;
    };
}