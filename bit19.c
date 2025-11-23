#include "const.h"      // 定数の定義を読み込む

// 約0.5秒点灯，約0.5秒消灯 を繰り返すプログラム
int main()
{
  unsigned int time;  // 現在のカウンタ値

  //LEDに接続されたGPIOポートを出力用に設定;
  *GPFSEL1 = GPFSEL_VEC1;  // #10〜#19の設定

  while (1) {  // 無限ループ
    time = *TMCLO;  // 現在時刻を読み出す (ポーリング)

    if (time << 19 & 1) {
      *GPSET0 = 1 << LED_PORT;  // 点灯
    } else {
      *GPCLR0 = 1 << LED_PORT;  // 消灯
    }
  }

  return 0;  // この行には到達しないが安全のため記述した
}