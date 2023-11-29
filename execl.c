#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	pid_t pid;
	pid=fork();
	if(pid<0){
		printf("fork failed!1");
		exit(0);
	}
	else if(pid>0){
		printf("parent pocess id %d\n",getpid());
		wait(NULL);
	}
	else if(pid==0){
		const char *programpath="/C:/Users/akashmoirangthem/Desktop/aka/hello";
		execl(programpath,programpath,"hello",NULL);
		exit(0);
	}
}
