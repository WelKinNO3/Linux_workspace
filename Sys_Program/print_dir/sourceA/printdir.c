#include "stdio.h"
#include "unistd.h"
#include "dirent.h"
void print_dir	(
			char * Path,		
			int          depth
		);		

	 


int main (char argv ,char * argc)
{
	
	DIR * temp_dir;
	struct dirent * enter;
	printf("\n printf /home/xhh/GIT_STORGE/workdir \n");
#if 0
	if(temp_dir = opendir("/home/xhh/GIT_STORGE/workdir")==NULL)
	{
		printf("open error \n");
		return 0;
	}else
	printf("open right \n");
	if((enter = readdir(temp_dir))!=NULL)
	{
		printf("readdir right ! \n");
		

	}
	closedir(temp_dir);
#endif
	print_dir("/home/xhh/GIT_STORGE/workdir",0);
	printf("done \n");
	return  0 ;



}
