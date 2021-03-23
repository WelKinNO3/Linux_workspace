#include "stdio.h"
#include "unistd.h"




int main (char argv ,char * argc)
{
	pid_x pid_buff;
	printf("before fork ! \n");
	pid_buff = fork();
	printf("after fork: pid_buff = %d \r\n",pid_buff);
	return  0 ;



}
