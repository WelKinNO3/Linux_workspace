#include "sys/types.h"
#include "sys/stat.h"
#include "unistd.h"
#include "fcntl.h"
#include "stdio.h"

int main(char agrv,char * agrc)
{

	int fd;
	fd = open("./b.txt",O_RDONLY|O_CREAT,0666);
	if(fd<0)
		printf("open error! \n");

	printf("fd = %d \n",fd);
	close(fd);
	return 0;


}
