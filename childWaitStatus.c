#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	int status=0;
	pid_t pid;
	pid=fork();
	if(pid<0){
		printf("fork failed!!!\n");
		exit(0);
	}
	else if(pid>0){
		wait(&status);
		if(WIFEXITED(status)){
			int code =WEXITSTATUS(status);
			printf("Normal Termination\n");
			printf("status code:%d\n",code);
		}
		else if(WIFSIGNALED(status)){
			int code= WTERMSIG(status);
			printf("Abnormal Termination\n");
			printf("status code:%d\n",code);
		}
		exit(0);
	}
	else if(pid==0){
		abort();
		exit(0);
	}
	return 0;
}
