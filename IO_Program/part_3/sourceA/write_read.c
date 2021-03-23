#include "unistd.h"
#include "stdio.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/stat.h"

#define BuffSize 100

int main (int argv ,char** argc)
{
	int fd;

	fd = open("./a.txt",O_RDONLY|O_WRONLY|O_CREAT,0666);

	write(fd,"123",3);

	lseek(fd,100,SEEK_CUR);

	write(fd,"123",3);

	close(fd);

	return 0;
}




