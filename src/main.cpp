#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include <emscripten.h>

#include "utils/minSono.h"
#include "utils/maxSono.h"

void Main()
{
    // 背景を水色にする
    Scene::SetBackground(ColorF(0.8, 0.9, 1.0));

    printf("AIUEO2\n");
    int a = 10;
    int b = 100;
    printf("%d\n", minSono(a, b));
    printf("%d\n", maxSono(a, b));

    Platform::Web::System::SetMainLoop([&]() {
        if (!System::Update())
        {
            ::emscripten_cancel_main_loop();
        }
    });
}

void aiueo()
{
    int a = 0;
    int b = 10;
}