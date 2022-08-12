#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int num)
{
	write(STDOUT_FILENO, "Closed Process!\n", 15);
}

int main(void)
{
	signal(SIGINT, handler);
	printf("PID: %d\n", getpid());
}
