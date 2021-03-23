#include "unistd.h"
#include "stdio.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/stat.h"

#define BuffSize 100

int main (int argv ,char** argc)
{
	int fd1,fd2;
	char databuff[BuffSize];
	int readsize;

	if(argv != 3)
	{
		printf("pram error!\r\n");
		return 1;
	}

	fd1 = open(argc[1],O_RDONLY);
	fd2 = open(argc[2],O_WRONLY|O_CREAT,0666);

	if(fd1 <0 || fd2 <0)
	{
		printf("open error \r\n");
		return 1;
	}

	do
	{
	readsize = read(fd1,databuff,BuffSize);
	write(fd2,databuff,readsize);
	}while(readsize>0);

	close(fd1);
	close(fd2);
	return 0;
}




