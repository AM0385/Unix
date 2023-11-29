#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main(){
	pid_t pid,child,parent;
	pid=fork();
	if(pid==0){
		child=getpid();
		printf("I am child and my process Id is :%d\n",child);
	}
	else{
		parent=getpid();
		printf("I am Parent process and my process Id is: %d\n",parent);
	}
	return 0;
}
