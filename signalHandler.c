#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>

void myHandler(int isig){
	printf("Inside myHandler function, the signal is %d",isig);
}

int main(void){
	void (*pfRet)(int);
	while(1){
		pfRet=signal(SIGHUP,myHandler);
		pfRet=signal(SIGINT,myHandler);
		pfRet=signal(SIGQUIT,myHandler);
		pfRet=signal(SIGILL,myHandler);
		pfRet=signal(SIGTRAP,myHandler);
		pfRet=signal(SIGABRT,myHandler);
		pfRet=signal(SIGBUS,myHandler);
		pfRet=signal(SIGKILL,myHandler);
	}
	return 0;
}
