#include "sys/types.h"
#include "sys/stat.h"
#include "unistd.h"
#include "fcntl.h"
#include "stdio.h"

#define MODEL_DEBUG 	0 
#define MODEL_LUACH 	1

#define MODEL	MODEL_LUACH

#if (MODEL==MODEL_LUACH)

#define ADR_BLUE	"/sys/class/leds/blue/brightness"

#define ADR_RED		"/sys/class/leds/red/brightness"

#define ADR_GREEN	"/sys/class/leds/green/brightness"

#else

#define ADR_BLUE	"./bulebrightness.txt"

#define ADR_RED		"./redbrightness.txt"

#define ADR_GREEN	"./greenbrightness.txt"

#endif

typedef enum
{
	FD_RED,
	FD_GREEN,
	FD_BLUE,
	FD_NUM
}FD_ENUMSTRUCT;

int main(char agrv,char * agrc)
{

	int fd[3],i;
	fd[FD_RED] 	= open(ADR_RED,O_WRONLY|O_CREAT,0666);
	fd[FD_GREEN]	= open(ADR_GREEN,O_WRONLY|O_CREAT,0666);
	fd[FD_BLUE]	= open(ADR_BLUE,O_WRONLY|O_CREAT,0666);		//打开驱动文件提供的控制文件 
	for(i= 0;i<FD_NUM;i++)
	{
		if(fd[i]<0)	printf("fd %d open error! \n",i);
	}
	for(i=0;i<FD_NUM;i++)
	{
		write(fd[i],"255",sizeof("255"));
		sleep(1);
		write(fd[i],"0",sizeof("0"));
		sleep(1);
	}
	for(i=0;i<FD_NUM;i++)	
	close(fd[i]);

	return 0;


}
