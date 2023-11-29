#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
// when parent has terminated and child is asleep!!!
int main(){
	pid_t pid, child, parent;
	pid=fork();
	if(pid<0){
		printf("fork failed!!!\n");
		exit(0);
	}
	else if(pid==0){
		child=getpid();
		printf("Child process(pid:%d) started\n",child);
		sleep(5);
		printf("Child process(pid:%d) completed\n",child);
	}
	else{
		parent=getpid();
		printf("parent process(pid:%d) started\n",parent);
		printf("parent process(pid:%d) terminated\n",parent);

	}
	return 0;
}
