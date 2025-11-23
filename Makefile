prefix = arm-none-eabi-
AS = $(prefix)as
LD = $(prefix)ld
CC = $(prefix)gcc
OBJCOPY = $(prefix)objcopy
LDFLAGS = -m armelf

# 生成規則
all: light.img

%.img: %.elf
		$(OBJCOPY) $< -O binary $@
%.elf: %.o init.o
		$(LD) $(LDFLAGS) $+ -o $@
%.o: %.c const.h
		$(CC) -c $< -o $@

init.o: init.s
		$(AS) $< -o $@

# 疑似ターゲットであることを明示
.PHONY: clean

# .img, .elf, .oファイルやバックアップファイル等を削除
clean:
	rm -f *.img *.elf *.o *~ a.out