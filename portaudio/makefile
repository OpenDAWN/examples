CC=gcc
C_SRCS := $(wildcard ./*.c)
C_OBJS := ${C_SRCS:.c=.o}

all:
	$(CC) $(C_SRCS) -DHV_SIMD_NONE -o Heavy
