#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

#include<sys/types.h>

int main(){
	int fd[2];
	pid_t pid;
	char buff[20];
	pipe(fd);
	pid=fork();

	if(pid==0){
		close(fd[0]);
		write(fd[1],"HEllo",5);
		printf("I am Writing Hello to parent \n");
		close(fd[1]);
	}

	if(pid>0){
		close(fd[1]);
		read(fd[0],buff,5);
		printf("MEssage Retrived:%s\n",buff);
		close(fd[0]);
	}
return 0;
}
