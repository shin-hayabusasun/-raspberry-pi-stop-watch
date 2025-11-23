#include "const.h"

int main()
{
    *GPFSEL0 = GPFSEL_VEC0;
    *GPFSEL1 = GPFSEL_VEC1;
    *GPFSEL2 = GPFSEL_VEC2;

    // フレームバッファ例（渦巻き模様や任意のパターンを設定）
    char frame_buffer[8] = {
        0b11100001,
        0b11011110,
        0b10110011,
        0b01101101,
        0b10110110,
        0b11011101,
        0b11101011,
        0b11110111
    };

    int row[] = {
        ROW1_PORT, ROW2_PORT, ROW3_PORT, ROW4_PORT,
        ROW5_PORT, ROW6_PORT, ROW7_PORT, ROW8_PORT
    };
    int col[] = {
        COL1_PORT, COL2_PORT, COL3_PORT, COL4_PORT,
        COL5_PORT, COL6_PORT, COL7_PORT, COL8_PORT
    };

    int clr = 0, set = 0;
    for (int i = 0; i < 8; i++) {
        clr |= 1 << col[i];
        set |= 1 << row[i];
    }

    int current_row = 0;
    unsigned int target = *TMCLO + 125000;  // 0.125 秒後の目標時刻

    while (1) {
        unsigned int time = *TMCLO;

        if (time >= target) {
            // 前の行を消灯
            *GPSET0 = 1 << row[current_row];

            // 次の行を選択
            current_row = (current_row + 1) % 8;

            // 列を全消灯
            *GPCLR0 = clr;

            // 対象行のパターンに従って列をセット
            for (int j = 0; j < 8; j++) {
                if ((frame_buffer[current_row] >> (7 - j)) & 1) {
                    *GPCLR0 = 1 << col[j];  // ドットON（LOW）
                } else {
                    *GPSET0 = 1 << col[j];  // ドットOFF（HIGH）
                }
            }

            // 対象行をアクティブにする
            *GPCLR0 = 1 << row[current_row];

            // 次の目標時刻を設定
            target += 125000;
        }
    }

    return 0;
}
