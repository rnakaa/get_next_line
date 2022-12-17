#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include"nnn.h"

int main(void)
{
	static char aaa[10];
	int fd = open("nnn.txt",O_RDONLY);
	
	read(fd,aaa,5);
	printf("%s\n",aaa);
	read(fd,aaa,5);
	printf("%s\n",aaa);
	return 0;
}
