#include "minitalk.h"

void char_to_bits(unsigned char c, pid_t pid)
{
	int count;

	count = 8;
		while(count-- > 0)
	{
		if(!(c & 128))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c << 1;
	}
}

#include <stdio.h>
int main(int argc, char *argv[])
{ 
	int i;
	pid_t pid;

	pid = ft_atoi(argv[1]);
	i = 0;
	if(argc != 3)
		ft_printf("Error %s", argv[2]);
	else
	{
		while(argv[2][i])
		{
			char_to_bits(argv[2][i], pid);
			i++;
			ft_printf("\n");
		}

	}
	ft_printf("\n");
}
