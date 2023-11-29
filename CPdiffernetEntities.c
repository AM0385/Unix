#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int global=100;

int main(){
	int local =10;
	pid_t pid;
	pid=fork();

	if(pid<0){
		printf("fork failed!!\n");
		exit(0);
	}
	else if(pid==0){
		local++;
		global++;
		printf("For child process(pid:%d), local=%d, global=%d \n",getpid(),local,global);
		exit(0);
	}
	else if(pid>0){
		sleep(2);
		printf("For parent local=%d, global=%d",local,global);
	}
	return 0;
}
