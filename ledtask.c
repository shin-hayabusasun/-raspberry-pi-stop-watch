#include "const.h"


int main()
{
  *GPFSEL0 = GPFSEL_VEC0;
  *GPFSEL1 = GPFSEL_VEC1;
  *GPFSEL2 = GPFSEL_VEC2;

    unsigned int time;
    unsigned int target1, target2;
// タスク1, タスク2の目標時刻
  target1 = *TMCLO + 750000;  // 現在時刻の1ミリ秒後
  target2 = target1 + 250000;  // タスク1の1.5秒後

  while (1) {  // 無限ループ
    time = *TMCLO;  // 現在時刻を読み出す (ポーリング)

    // タスク・ディスパッチ
    if (time >= target1) {
      //LEDを点灯する;
      *GPCLR0 = 1 << LED_PORT;
      target1 += 1000000;  // 3秒足す
    }
    if (time >= target2) {
      //LEDを消灯する;
      *GPSET0 = 1 << LED_PORT;
      target2 += 1000000;  // 3秒足す
    }
  }
   return 0;  // 安全のため記述
}