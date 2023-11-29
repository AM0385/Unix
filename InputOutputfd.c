#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

	int n;
	char buff[255];
	while((n=read(0,buff,sizeof(buff)))>0){
		write(1,buff,n);
	}
	return 0;
}
