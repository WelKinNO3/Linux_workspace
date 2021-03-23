#include "sys/types.h"
#include "sys/stat.h"
#include "unistd.h"
#include "fcntl.h"
#include "stdio.h"
#include "../includes/GPIO_Contral_Beep.h"
#include "../includes/DEBUG.h"

typedef enum
{
	FD_RED,
	FD_GREEN,
	FD_BLUE,
	FD_NUM
}FD_ENUMSTRUCT;

int main(char agrv,char * agrc)
{
	int count;
	beep_initial();
	
	for(count = 0; count < 2;count ++)
	{
		beep_contral(Contral_OPEN);
		sleep(1);
		beep_contral(Contral_CLOSE);
		sleep(1);
	}

	return 0;


}
