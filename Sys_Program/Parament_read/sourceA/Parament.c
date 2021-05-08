#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "fcntl.h"
#include "sys/types.h"
#include "unistd.h"
#include "sys/wait.h"
#include "sys/stat.h"



int main (int argv ,char ** argc)
{
	int read_count, parament_count,argument_count;
	char **parament[argv];
	char **argument[argv];

	for(read_count=1,parament_count=0,argument_count = 0;\
	    read_count < argv;\
	    read_count ++	)
	{
		if(*(argc+read_count)[0] == '-')
		{
	//		printf("%s\n",*(argc+read_count));
			
//			printf("%s\n",*(argc+read_count+1));
			*(parament+parament_count++)=(*(argc+read_count));
	//		printf("parament = %s\n",*(parament+parament_count-1));
		}
		else if(1)
		{
			
			printf("%s\n",*(argc+read_count));
			*(argument+argument_count++)=*(argc+read_count);
	       	}

	
	
	}
	printf("has %d parament \n",parament_count);
#if 1
	for(read_count = 0; (read_count<parament_count);read_count++)
	{
		printf("option_%d : %s\n",read_count,(char *)*(parament+read_count));
	
	
	}
	for(read_count = 0;(read_count<argument_count);read_count++)
	{
		printf("argument_%d : %s\n",read_count,(char *)(*argument+read_count));
	
	
	}
#endif
	return  0 ;



}
