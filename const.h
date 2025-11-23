#define GPIO_BASE       (int *)0x3f200000
#define GPFSEL0         (GPIO_BASE + 0)  
#define GPFSEL1         (GPIO_BASE + 1) 
#define GPFSEL2         (GPIO_BASE + 2) 
#define GPSET0          (GPIO_BASE + 7) 
#define GPCLR0          (GPIO_BASE + 10) 
#define GPLEV0          (GPIO_BASE + 13)
//#define GPFSEL_VEC1    1
#define LED_PORT        10 
#define SW1_PORT        13
#define SW2_PORT        26


// GPFSELxに設定する値
#define GPFSEL_VEC0     0x01201000  // GPFSEL0用 (#4, #7, #8 が出力)
#define GPFSEL_VEC1     0x01249041  // GPFSEL1用 (#10, #12, #14〜18 が出力)
#define GPFSEL_VEC2     0x00209249  // GPFSEL2用 (#20〜25, #27 が出力)

// 各装置が接続されているGPIO番号
//#define LED_PORT      10

#define COL1_PORT       27
#define COL2_PORT       8
#define COL3_PORT       25
#define COL4_PORT       23
#define COL5_PORT       24
#define COL6_PORT       22
#define COL7_PORT       17
#define COL8_PORT       4

#define ROW1_PORT       14
#define ROW2_PORT       15
#define ROW3_PORT       21
#define ROW4_PORT       18
#define ROW5_PORT       12
#define ROW6_PORT       20
#define ROW7_PORT       7
#define ROW8_PORT       16

// タイマーを操作するための番地
#define TIMER_BASE      (unsigned int *)0x3f003000
#define TMCLO           (TIMER_BASE + 1)        // タイマー下位32ビット

#define TIMER_HZ    (1000 * 1000)    /* タイマの周波数 (= 1秒を表すカウンタ値) */