#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(){
	int n,fd1,fd2;
	char buf[1024];
	fd1=open("orphan.c",O_RDONLY);
	fd2=open("hello.c",O_WRONLY);
	while((n=read(fd1,buf,sizeof(buf)))>0){
		write(fd2,buf,n);
	}
	close(fd1);
	close(fd2);
	return 0;
}
