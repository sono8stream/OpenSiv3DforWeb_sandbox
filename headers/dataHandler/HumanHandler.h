#pragma once
#include "data/Human.h"
#include "dataHandler/HandlerEvent.h"

using namespace std;

namespace dataHandler
{
    /*
    Humanクラスの編集窓口を担う
    Facadeパターンのような
    これはイベントリスナーのようなクラスにコンポジットされる
    */
    class HumanHandler
    {
        shared_ptr<data::Human> pHuman;

    public:
        HumanHandler(int hp, int attack, int speed);

        void damageHp(const int damage);
        void addDamageListener(function<void(int)> listener);
        void hogeg();
    };
}