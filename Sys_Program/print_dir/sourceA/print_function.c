#include "stdio.h"
#include "sys/stat.h"
#include "dirent.h"
#include "stdlib.h"
#include "string.h"

void print_dir(
		char * Path,		
		int  depth
	      )
{
	DIR * temp_dir;
	struct dirent * enter;
	struct stat   temp_stat;
//	printf("test : Path = %s \n",Path);
	temp_dir = opendir(Path);//打开当前路径并获取相关的目录描述符
	if(temp_dir == NULL)
	{
		printf("there is an error of failing to open intentive about %s!\n",Path);
		return ;
	
	}
	chdir(Path);//进入当前路径
	while((enter = readdir(temp_dir)) != NULL)
	{//当前没有到目录流尽头
		lstat(enter->d_name,&temp_stat);//获取当前文件（目录）的描述符
#if 0
		{
			printf("there is an error of failing to read intentive about %s!\n",enter->d_name);
			return ;
		}
#endif
		if(S_ISDIR(temp_stat.st_mode))//是否为目录
		{
			if((strcmp(".",enter->d_name)==0)||
			  ( strcmp("..",enter->d_name)==0)) continue;
			printf("%*s%s/\n",depth,"",enter->d_name);
			print_dir(enter->d_name,depth+4);
		}
		else
		{
			printf("%*s%s/\n",depth,"",enter->d_name);
		}
	}
	chdir("..");
	closedir(temp_dir);
}
