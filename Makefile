CFLAGS=-c -Wall -O2
LIBS = -lm -lpthread

all: libmax7219.a

libmax7219.a: max7219.o
	ar -rc libmax7219.a max7219.o ;\
	sudo cp libmax7219.a /usr/local/lib ;\
	sudo cp max7219.h /usr/local/include

max7219.o: max7219.h max7219.c
	$(CC) $(CFLAGS) max7219.c

clean:
	rm *.o libmax7219.a
