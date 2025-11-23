#include "const.h" 
int main()
{
  // GPIOの機能設定
  *GPFSEL0 = GPFSEL_VEC0;  // #0〜#9の設定
  *GPFSEL1 = GPFSEL_VEC1;  // #10〜#19の設定
  *GPFSEL2 = GPFSEL_VEC2;  // #20〜#29の設定
char frame_buffer[]={

    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
};




   int row[]={
    ROW1_PORT,
    ROW2_PORT,
    ROW3_PORT,
    ROW4_PORT,
    ROW5_PORT,
    ROW6_PORT,
    ROW7_PORT,
    ROW8_PORT
   };

   int col[]={
    COL1_PORT,
    COL2_PORT,
    COL3_PORT,
    COL4_PORT,
    COL5_PORT,
    COL6_PORT,
    COL7_PORT,
    COL8_PORT
   };

  int set=0;
  int clr=0;

for(int i=0;i<8;i++){
    clr|=1<<col[i];
    set|=1<<row[i];
}

int x = 0;

while(1){
  int sw = *GPLEV0;
  if (sw & (1 << SW1_PORT) ){
    frame_buffer[x/8]= 1 << (7-x%8)^frame_buffer[x/8];
    x = (x + 1) % 64;  // 次の点へ. 64になったら0に戻す
  }
  for (int k = 0; k < 10; k++) {
  for(int i=0;i< 8;i++ ){ 
    *GPCLR0=clr;
     *GPSET0=set;
    
  for (int j = 0; j < 500; j++) ;

  set=1<<row[((i+7)%8)];
  clr=1<<row[i];
  
     for(int j=0;j<8;j++){
      if((frame_buffer[i] >> (7-j) )& 1) {
         set |= 1 << col[j];}
    else{
        clr |= 1<< col[j];
    }
  
     }
 

}
}
}




     




  return 0;  // init.sに戻る
}