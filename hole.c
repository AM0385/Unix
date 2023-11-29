#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd1, fd2;
	char buff1[]="qwertyuiop";
	char buff2[]="asdfghjklz";
	fd1=open("file.hole",O_WRONLY);
	int curpos=write(fd1,buff1,sizeof(buff1));
	lseek(fd1,16384,SEEK_SET);
	write(fd1,buff2,sizeof(buff2));
	fd2=("file.nohole",O_WRONLY);
	while((lseek(fd2,0,SEEK_CUR))>16394){
		write(fd2,buff1,sizeof(buff2));
	}
}
