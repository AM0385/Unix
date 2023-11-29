#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

void myHandler(int isig){
	printf("signal number is %d",isig);
}
int main(){
	void(*pfRet)(int);
	while(1){
	pfRet=signal(SIGINT,myHandler);
	pfRet=signal(SIGINT,myHandler);
	pfRet=signal(SIGFPE,myHandler);
	pfRet=signal(SIGKILL,myHandler);
	}
	return 0;
}
