#pragma once
#include "dataHandler/HandlerEvent.h"

namespace dataHandler
{
    /*
    イベントハンドラ生成クラス
    対応するハンドライベントIDを生成する
    */
    class HandlerEventFactory
    {
    public:
        virtual HandlerEvent createEvent();
        };
}