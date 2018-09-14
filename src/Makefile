CFLAGS="-Wall -g"

all: bin/main.o
	$(CC) $(CFLAGS) -c -o $@ $<

main.o: implementation.c obj/types.h obj/object.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f "test"
