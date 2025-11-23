#include "const.h" 
int main()
{
    //演習2-4
  // GPIOの機能設定
  *GPFSEL0 = GPFSEL_VEC0;  // #0〜#9の設定
  *GPFSEL1 = GPFSEL_VEC1;  // #10〜#19の設定
  *GPFSEL2 = GPFSEL_VEC2;  // #20〜#29の設定


while(1){
  // (2,3) を点灯する
  // COL3のみ1, それ以外の列は0にする
  *GPCLR0 = 1 << COL1_PORT
          | 1 << COL2_PORT
          | 1 << COL3_PORT
          | 1 << COL8_PORT;
         
  *GPSET0 = 1 << COL4_PORT
          | 1 << COL5_PORT
          | 1 << COL6_PORT
          | 1 << COL7_PORT;

  // ROW2のみ0, それ以外の行は1にする
  *GPSET0 = 1 << ROW8_PORT
          | 1 << ROW3_PORT
          | 1 << ROW4_PORT
          | 1 << ROW5_PORT
          | 1 << ROW6_PORT
          | 1 << ROW7_PORT
          | 1 << ROW2_PORT;
  *GPCLR0 = 1 << ROW1_PORT;

  // ** ここに待ち時間が必要 **
  int i;
  for (i = 0; i < 500; i++) ;

  *GPCLR0 = 1 << COL1_PORT
          | 1 << COL2_PORT
          | 1 << COL3_PORT
          | 1 << COL5_PORT
          | 1 << COL6_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL4_PORT;

 *GPCLR0 =  1 << ROW1_PORT
          | 1 << ROW3_PORT
          | 1 << ROW5_PORT
          | 1 << ROW6_PORT
          | 1 << ROW4_PORT
          | 1 << ROW2_PORT
          | 1 << ROW8_PORT
          | 1 << ROW7_PORT;



  *GPCLR0 = 1 << COL1_PORT
          | 1 << COL2_PORT
          | 1 << COL4_PORT
          | 1 << COL5_PORT
          | 1 << COL6_PORT
          | 1 << COL7_PORT;
          
  *GPSET0 = 1 << COL3_PORT  | 1 << COL8_PORT  ;

  // ROW2のみ0, それ以外の行は1にする
  *GPSET0 = 1 << ROW1_PORT
          | 1 << ROW3_PORT
          | 1 << ROW4_PORT
          | 1 << ROW5_PORT
          | 1 << ROW6_PORT
          | 1 << ROW7_PORT
          | 1 << ROW8_PORT;
  *GPCLR0 = 1 << ROW2_PORT ;

    int j;
  for (j = 0; j < 500; j++) ;

  *GPCLR0 = 1 << COL1_PORT
          | 1 << COL3_PORT
          | 1 << COL4_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL4_PORT;

 *GPCLR0  = 1 << ROW1_PORT
          | 1 << ROW2_PORT
          | 1 << ROW3_PORT
          | 1 << ROW4_PORT
          | 1 << ROW5_PORT
          | 1 << ROW6_PORT
          | 1 << ROW7_PORT
          | 1 << ROW8_PORT;



  *GPCLR0 = 1 << COL1_PORT
          | 1 << COL3_PORT
          | 1 << COL4_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT;
          
  *GPSET0 = 1 << COL2_PORT  | 1 << COL5_PORT  | 1 << COL6_PORT;

  // ROW2のみ0, それ以外の行は1にする
  *GPSET0 = 1 << ROW1_PORT
          | 1 << ROW2_PORT
          | 1 << ROW4_PORT
          | 1 << ROW5_PORT
          | 1 << ROW6_PORT
          | 1 << ROW7_PORT
          | 1 << ROW8_PORT;
  *GPCLR0 = 1 << ROW3_PORT ;

   for (j = 0; j < 500; j++) ;

  *GPCLR0 = 1 << COL1_PORT
          | 1 << COL3_PORT
          | 1 << COL4_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL4_PORT;

 *GPCLR0  = 1 << ROW1_PORT
          | 1 << ROW2_PORT
          | 1 << ROW3_PORT
          | 1 << ROW4_PORT
          | 1 << ROW5_PORT
          | 1 << ROW6_PORT
          | 1 << ROW7_PORT
          | 1 << ROW8_PORT;








 *GPCLR0 = 1 << COL2_PORT
          | 1 << COL3_PORT
          | 1 << COL5_PORT
          | 1 << COL6_PORT
          | 1 << COL8_PORT;
          
  *GPSET0 = 1 << COL1_PORT  | 1 << COL4_PORT  | 1 << COL7_PORT;

  // ROW2のみ0, それ以外の行は1にする
  *GPSET0 = 1 << ROW1_PORT
          | 1 << ROW2_PORT
          | 1 << ROW3_PORT
          | 1 << ROW5_PORT
          | 1 << ROW6_PORT
          | 1 << ROW7_PORT
          | 1 << ROW8_PORT;
  *GPCLR0 = 1 << ROW4_PORT ;


  for (j = 0; j < 500; j++) ;

  *GPCLR0 = 1 << COL1_PORT
          | 1 << COL3_PORT
          | 1 << COL4_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL4_PORT;

 *GPCLR0  = 1 << ROW1_PORT
          | 1 << ROW2_PORT
          | 1 << ROW3_PORT
          | 1 << ROW4_PORT
          | 1 << ROW5_PORT
          | 1 << ROW6_PORT
          | 1 << ROW7_PORT
          | 1 << ROW8_PORT;

*GPCLR0 = 1 << COL1_PORT
          | 1 << COL3_PORT
          | 1 << COL4_PORT
          | 1 << COL6_PORT
          | 1 << COL7_PORT;
          
  *GPSET0 = 1 << COL2_PORT  | 1 << COL5_PORT  | 1 << COL8_PORT;

  // ROW2のみ0, それ以外の行は1にする
  *GPSET0 = 1 << ROW1_PORT
          | 1 << ROW2_PORT
          | 1 << ROW3_PORT
          | 1 << ROW4_PORT
          | 1 << ROW6_PORT
          | 1 << ROW7_PORT
          | 1 << ROW8_PORT;
  *GPCLR0 = 1 << ROW5_PORT ;

   for (j = 0; j < 500; j++) ;

 *GPCLR0 = 1 << COL1_PORT
          | 1 << COL3_PORT
          | 1 << COL4_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL4_PORT;

 *GPCLR0  = 1 << ROW1_PORT
          | 1 << ROW2_PORT
          | 1 << ROW3_PORT
          | 1 << ROW4_PORT
          | 1 << ROW5_PORT
          | 1 << ROW6_PORT
          | 1 << ROW7_PORT
          | 1 << ROW8_PORT;

*GPCLR0 = 1 << COL1_PORT
          | 1 << COL2_PORT
          | 1 << COL4_PORT
          | 1 << COL5_PORT
          | 1 << COL6_PORT
          | 1 << COL8_PORT;
          
  *GPSET0 = 1 << COL3_PORT  | 1 << COL7_PORT ;

  // ROW2のみ0, それ以外の行は1にする
  *GPSET0 = 1 << ROW1_PORT
          | 1 << ROW2_PORT
          | 1 << ROW3_PORT
          | 1 << ROW4_PORT
          | 1 << ROW5_PORT
          | 1 << ROW7_PORT
          | 1 << ROW8_PORT;
  *GPCLR0 = 1 << ROW6_PORT ;
     for (j = 0; j < 500; j++) ;

   *GPCLR0 = 1 << COL1_PORT
          | 1 << COL3_PORT
          | 1 << COL4_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL4_PORT;

 *GPCLR0  = 1 << ROW1_PORT
          | 1 << ROW2_PORT
          | 1 << ROW3_PORT
          | 1 << ROW4_PORT
          | 1 << ROW5_PORT
          | 1 << ROW6_PORT
          | 1 << ROW7_PORT
          | 1 << ROW8_PORT;


*GPCLR0 = 1 << COL1_PORT
          | 1 << COL2_PORT
          | 1 << COL3_PORT
          | 1 << COL5_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT;
          
  *GPSET0 = 1 << COL4_PORT  | 1 << COL6_PORT ;

  // ROW2のみ0, それ以外の行は1にする
  *GPSET0 = 1 << ROW1_PORT
          | 1 << ROW2_PORT
          | 1 << ROW3_PORT
          | 1 << ROW4_PORT
          | 1 << ROW5_PORT
          | 1 << ROW6_PORT
          | 1 << ROW8_PORT;
  *GPCLR0 = 1 << ROW7_PORT ;
     for (j = 0; j < 500; j++) ;


   *GPCLR0 = 1 << COL1_PORT
          | 1 << COL3_PORT
          | 1 << COL4_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL4_PORT;

 *GPCLR0  = 1 << ROW1_PORT
          | 1 << ROW2_PORT
          | 1 << ROW3_PORT
          | 1 << ROW4_PORT
          | 1 << ROW5_PORT
          | 1 << ROW6_PORT
          | 1 << ROW7_PORT
          | 1 << ROW8_PORT;

*GPCLR0 = 1 << COL1_PORT
          | 1 << COL2_PORT
          | 1 << COL3_PORT
          | 1 << COL4_PORT
          | 1 << COL6_PORT
          | 1 << COL7_PORT
        | 1 << COL8_PORT;
          
  *GPSET0 = 1 << COL5_PORT  ;

  // ROW2のみ0, それ以外の行は1にする
  *GPSET0 = 1 << ROW1_PORT
          | 1 << ROW2_PORT
          | 1 << ROW3_PORT
          | 1 << ROW4_PORT
          | 1 << ROW5_PORT
          | 1 << ROW7_PORT
          | 1 << ROW6_PORT;
  *GPCLR0 = 1 << ROW8_PORT ;

   for (j = 0; j < 500; j++) ;
*GPCLR0 = 1 << COL1_PORT
          | 1 << COL3_PORT
          | 1 << COL4_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL7_PORT
          | 1 << COL8_PORT
          | 1 << COL4_PORT;

 *GPCLR0  = 1 << ROW1_PORT
          | 1 << ROW2_PORT
          | 1 << ROW3_PORT
          | 1 << ROW4_PORT
          | 1 << ROW5_PORT
          | 1 << ROW6_PORT
          | 1 << ROW7_PORT
          | 1 << ROW8_PORT;
  







}



  return 0;  // init.sに戻る
}