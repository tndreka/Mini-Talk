#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/wait.h>


void nope(int n)
{
	printf("nooopppeee\n");
}
int main (int ac, char **av)
{
	signal(SIGINT, nope);
	signal(SIGTERM, nope);
	int id = getpid();
	while(1)
	{
		printf("not this time !! :P %d\n", id);
		sleep(1);
	}
	return 0;
}