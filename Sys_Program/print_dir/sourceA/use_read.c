#include "stdio.h"
#include "unistd.h"




int main (char argv ,char * argc)
{

	char temp_buff[120];
	int buff_length;
	while(1)
	{
		buff_length = read(0,temp_buff,120);
		if(buff_length)
			write(1,temp_buff,buff_length);
		else
			write(1,"nothing!\n",sizeof("nothing!\n"));
		write(1,"1s \r\n",sizeof("1s"));
		sleep(1);
	
	}
	return  0 ;



}
