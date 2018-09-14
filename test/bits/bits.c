#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ui8 unsigned char
#define ui32 unsigned int

struct ui32_bits {
	ui8 b[32];
};

int main(int argc, char** argv)
{
	printf("sizeof ui64 = %ld\n", sizeof(ui32));
	for(ui32 i = 0; i < 32; i++){
		printf("2^%d = %d\n", i, 1 << i);
	}
}
