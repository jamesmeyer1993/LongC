CC=gcc
CFLAGS=-Wall -g

all:
	lang
	string
	$CC -shared -lm bin/string.o -o longc.so

lang:
	cp -v src/lang.h bin
	cp -v src/trait.h bin
	cp -v src/comparable.h bin
	cp -v src/constructable.h bin
	cp -v src/constructable_from.h bin

string:
	$CC $CFLAGS -c src/string.c -o bin/string.o

clean:
	rm -v bin/*.o
