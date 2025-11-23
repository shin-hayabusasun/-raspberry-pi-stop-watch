#include "const.h"  // 定数の定義を読み込む

int main()
{
    unsigned int time;
    unsigned int target;
    int led_on = 0;  // 0: 消灯中, 1: 点灯中

    // LED に接続された GPIO ポートを出力用に設定
    *GPFSEL1 = GPFSEL_VEC1;

    // 最初の目標時刻を現在時刻 + 適当な遅延 (ここでは1000マイクロ秒)
    target = *TMCLO + 1000;

    while (1) {  // 無限ループ
        time = *TMCLO;  // 現在時刻を読み出す (ポーリング)

        if (time >= target) {
            if (led_on) {
                // LED が点灯中 → 消灯
                *GPCLR0 = 1 << LED_PORT;
                led_on = 0;
            } else {
                // LED が消灯中 → 点灯
                *GPSET0 = 1 << LED_PORT;
                led_on = 1;
            }

            // 次の目標時刻を設定 (1.5 秒後 = 1500000 マイクロ秒後)
            target += 1500000;
        }
    }

    return 0;  // 安全のため記述（到達しない）
}