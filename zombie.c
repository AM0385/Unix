#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
//when parent is asleep
int main(){
	pid_t pid, parent, child;
	pid=fork();
	if(pid<0){
		printf("fork failed!!!\n");
		exit(0);
	}
	else if(pid==0){
		child=getpid();
		printf("Child process(pid:%d) started\n",child);
		printf("Child process(pid:%d) completed \n",child);
		exit(0);
	}
	else{
		parent=getpid();
		printf("Parent process (pid:%d) started\n",parent);
		sleep(5);
		printf("Parent process(pid:%d) completed \n",parent);
	}
	return 0;
}
