CC=gcc
CFLAGS=-Wall
SRCS = \
./com.c \
./test_dh_parameter.c \

OBJS = $(SRCS:.c=.o)

TARGET= test_dh

all: $(TARGET)

.PHONY : clean

clean :
	rm -f $(TARGET) *.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)