#include "minitalk.h"

void char_to_bits(unsigned char c)
{
	int count;

	count = 8;
		while(count-- > 0)
	{
		if(!(c & 128))
			write(1, "0",1);
		else
			write(1, "1", 1);
		c = c << 1;
	}
}

#include <stdio.h>
int main(int argc, char *argv[])
{
	int c;

	c = 1;
	while(c < argc)
	{
		char_to_bits((unsigned char)argv[c]);
		printf("\n");
		c++;
	}
}
