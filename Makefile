CFLAGS = -Wall -g
CC = cc

all: cpress

cpress: main.o
	$(CC) $(CFLAGS) main.o -o cpress

clean:
	rm -f cpress *.o

