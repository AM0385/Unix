#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	struct stat buf;
	for(int x=0;x<argc;x++){
		printf("%s",argv[x]);
		lstat(argv[x],&buf);
		if(S_ISREG(buf.st_mode))
			printf("file is regular");
		if(S_ISDIR(buf.st_mode))
			printf("file is director");
		exit(0);
	}
	return 0;
}
