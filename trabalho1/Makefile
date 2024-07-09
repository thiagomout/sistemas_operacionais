CC = gcc

CFLAGS = -Wall -Wextra -O2

TARGET = memory-user

SRC = memory-user.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean
