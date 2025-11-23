#include "const.h"      // 定数の定義を読み込む

// 悪い例: LEDを点灯して消灯する（点灯時間短すぎ）
int main()
{
  while(1){
    int sw;

  // GPIOの機能設定

  // GPLEV0の値 (GPIO #0〜#31それぞれが読み取った値) をswに代入
  sw = *GPLEV0;

  // SW1が押されているか
  if (sw & (1 << SW1_PORT)) {
    // GPIOの機能設定
     *GPFSEL1 = GPFSEL_VEC1;  // #10〜#19の設定

    // LED点灯 (LED_PORTの出力を1にする)
    *GPSET0 = 1 << LED_PORT;
  }else{
    // LED消灯します
    *GPCLR0 = 1 << LED_PORT;
       }
  }
  return 0;  // init.sに戻る
}