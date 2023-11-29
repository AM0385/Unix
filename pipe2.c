#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys?types.h>

int main(){
	int fd1[2],fd2[2];
	pid_t pid;
	char buff[20];
	pipe(fd1);
	pipe(fd2);
	pid=fork;
	
}
