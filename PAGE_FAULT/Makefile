CC = gcc
CFLAGS = -Wall -Wextra

TARGET = pagefault

all: $(TARGET)

$(TARGET): pagefault.c
	$(CC) $(CFLAGS) -o $(TARGET) pagefault.c

clean:
	rm -f $(TARGET)
