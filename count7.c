#include "const.h"

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

int main()
{
    *GPFSEL0 = GPFSEL_VEC0;
    *GPFSEL1 = GPFSEL_VEC1;
    *GPFSEL2 = GPFSEL_VEC2;

    char frame_buffer[8] = {0};

    int row[] = { ROW1_PORT, ROW2_PORT, ROW3_PORT, ROW4_PORT,
                  ROW5_PORT, ROW6_PORT, ROW7_PORT, ROW8_PORT };
    int col[] = { COL1_PORT, COL2_PORT, COL3_PORT, COL4_PORT,
                  COL5_PORT, COL6_PORT, COL7_PORT, COL8_PORT };

    int clr = 0, set = 0;
    for (int i = 0; i < 8; i++) {
        clr |= 1 << col[i];
        set |= 1 << row[i];
    }

    int x = 0;
    while (1) {
        
        set_frame_buffer(frame_buffer, x);
        x = (x + 7) % 100;

        for (int k = 0; k < 300; k++) {
            for (int i = 0; i < 8; i++) {
                *GPCLR0 = clr;
                *GPSET0 = set;
                for (int j = 0; j < 8; j++) {
                    if ((frame_buffer[i] >> (7 - j)) & 1) {
                        *GPCLR0 = 1 << col[j];
                    } else {
                        *GPSET0 = 1 << col[j];
                    }
                }
                *GPCLR0 = 1 << row[i];
                for (int d = 0; d < 500; d++);
                *GPSET0 = 1 << row[i];
            }
        }
    }

    return 0;
}