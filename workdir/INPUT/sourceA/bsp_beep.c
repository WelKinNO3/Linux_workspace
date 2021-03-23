#include "stdio.h"
#include "../includes/GPIO_Contral_Beep.h"
#include "sys/stat.h"
#include "unistd.h"
#include "fcntl.h"
#include "../includes/DEBUG.h"

int beep_initial()
{
	
	int fd_export;
#if (MODEL_STATUS == MODEL_LAUNCH)	
	fd_export = open(GPIO_DIRECTORY,O_WRONLY);
#else
	fd_export = open(GPIO_DIRECTORY,O_WRONLY|O_CREAT,0666);
#endif	
	if(fd_export < 0 )
	{
		printf("There is error that open the export ! \n");
		return 1;
	}
	write(fd_export,GPIO_CONTRAL_INDEX,sizeof(GPIO_CONTRAL_INDEX));

	close(fd_export);

	return 0;

}


int beep_contral(
			Contral_Enum Operation_L
		)
{
	int fd_direction,fd_value;
#if (MODEL_STATUS)
//	fd_direction = open("/gpio""/direction",O_WRONLY);
	fd_direction = open(GPIO_CONTRAL"/gpio"GPIO_CONTRAL_INDEX"/direction",O_WRONLY);
#else
	fd_direction = open("./gpio_19_direction",O_WRONLY|O_CREAT,0666);
#endif
	if(fd_direction < 0 )
	{
		printf("There is error that open the direction ! \n");
		printf(GPIO_CONTRAL"/gpio"GPIO_CONTRAL_INDEX"/direction \n");
		return 1;
	}

#if (MODEL_STATUS)
	fd_value = open(GPIO_CONTRAL"/gpio"GPIO_CONTRAL_INDEX"/value",O_WRONLY);
#else
	fd_value = open("./gpio_19_value",O_WRONLY|O_CREAT,0666);
#endif
	if(fd_value < 0 )
	{
		printf("There is error that open the value ! \n");
		return 1;
	}

	write(fd_direction,"out",3);

	if(Operation_L == Contral_OPEN)
		write(fd_value,"1",1);
	else
		write(fd_value,"0",1);

	close(fd_direction);
	close(fd_value);

	return 0;
}



