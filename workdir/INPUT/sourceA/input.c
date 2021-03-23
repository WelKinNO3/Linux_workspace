#include "sys/types.h"
#include "sys/stat.h"
#include "unistd.h"
#include "fcntl.h"
#include "stdio.h"
//#include "../includes/GPIO_Contral_Beep.h"
//#include "../includes/DEBUG.h"
#include "linux/input.h"
#include "linux/input-event-codes.h"



#define key_path "/dev/input/by-path/platform-gpio-keys-event"
#define mouse_path "/dev/input/by-path/platform-ci_hdrc.1-usb-0:1.3:1.0-event-mouse"

int main(char agrv,char ** agrc)
{
	char * PATH;
	int fd_input;
	struct input_event event;

	if(agrv > 1)
	{
		PATH = agrc[1];
	}
	else
	{
		PATH = (char *)(mouse_path);
	}

	fd_input = open(PATH,O_RDONLY);

	if(fd_input < 0)
	{
		printf("There has an error of open the fd_input! \n");
		return 1 ;
	}

	while(1)
	{
		if(read(fd_input,&event,sizeof(event)) == sizeof(event))
		{
			if(event.type != EV_SYN)
			{
				printf("Event : time %1d.%1d,type %d ,code %d ,value %d\n",
					event.time.tv_sec,event.time.tv_usec,
					event.type,
					event.code,
					event.value);
			}
		
		}
			
	
	}
	close(fd_input);
	return 0;
}
