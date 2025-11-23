#include "const.h"

// 数字フォントデータ（4ビット幅×8行）
const char font4bit[10][8] = {
    {0xF,0x1,0x5,0x5,0x5,0x1,0xF,0xF}, // 0
    {0xF,0xB,0x3,0xB,0xB,0x1,0xF,0xF}, // 1
    {0xF,0x1,0xD,0x1,0x7,0x1,0xF,0xF}, // 2
    {0xF,0x1,0xD,0x1,0xD,0x1,0xF,0xF}, // 3
    {0xF,0x5,0x5,0x1,0xD,0xD,0xF,0xF}, // 4
    {0xF,0x1,0x7,0x1,0xD,0x1,0xF,0xF}, // 5
    {0xF,0x1,0x7,0x1,0x5,0x1,0xF,0xF}, // 6
    {0xF,0x1,0x5,0xD,0xD,0xD,0xF,0xF}, // 7
    {0xF,0x1,0x5,0x1,0x5,0x1,0xF,0xF}, // 8
    {0xF,0x1,0x5,0x1,0xD,0x1,0xF,0xF}  // 9
};

void set_frame_buffer(char *fb, int num) {
    int tens = num / 10;
    int ones = num % 10;
    for (int i = 0; i < 8; i++) {
        fb[i] = (font4bit[tens][i] << 4) | font4bit[ones][i];
    }
}

int main() {
    *GPFSEL0 = GPFSEL_VEC0;
    *GPFSEL1 = GPFSEL_VEC1;
    *GPFSEL2 = GPFSEL_VEC2;

    char frame_buffer[8] = {0};
    int row[] = { ROW1_PORT, ROW2_PORT, ROW3_PORT, ROW4_PORT,
                  ROW5_PORT, ROW6_PORT, ROW7_PORT, ROW8_PORT };
    int col[] = { COL1_PORT, COL2_PORT, COL3_PORT, COL4_PORT,
                  COL5_PORT, COL6_PORT, COL7_PORT, COL8_PORT };

    int clr = 0;
    for (int i = 0; i < 8; i++) {
        clr |= 1 << col[i];
    }

    int count = 0;
    int current_row = 0;

    unsigned int time;
    unsigned int target_count = *TMCLO + 100000;   // 1秒後
    unsigned int target_row = *TMCLO + 1000;        

    set_frame_buffer(frame_buffer, count);
     
    int btm = 0;
    int target_led_on=*TMCLO;
    int target_led_off=*TMCLO+500000;

    

    while (1) {
        int sw=*GPLEV0;
        time = *TMCLO;
        int sw1=SW1_PORT;
        int  sw2 = SW2_PORT;

        // 数字更新タスク（1秒周期）
        if ((time >= target_count) && (btm==1)) {
            count = (count+1 ) % 100;
            set_frame_buffer(frame_buffer, count);
            target_count += 100000;
        }
        if((time >= target_count) && (btm ==0)){
             target_count += 100000;
        }


        if (time >= target_row) {
            *GPSET0 = 1 << row[current_row];  // 現行行消灯
            current_row = (current_row + 1) % 8;

            *GPSET0 = clr;  // 全列消灯
            for (int j = 0; j < 8; j++) {
                if ((frame_buffer[current_row] >> (7 - j)) & 1) {
                    *GPCLR0 = 1 << col[j];  // ドット点灯
                } else {
                    *GPSET0 = 1 << col[j];  // ドット消灯
                }
            }
            *GPCLR0 = 1 << row[current_row];  // 新行点灯
            target_row += 1000;
        }

        if((sw & (1<<sw1)) && (btm==0)){
            btm=1;

        }
        if(sw & (1<<sw2)&& (btm==1)){
            btm=0;
        }
        if(time>=target_led_on){
            *GPSET0=1<<LED_PORT;
            target_led_on+=1000000;

        }
          if(time>=target_led_off){
            *GPCLR0=1<<LED_PORT;
            target_led_off+=1000000;

        }


    }

    return 0;
}