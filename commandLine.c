#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
	if(argc<=0){
		printf("\nInsufficient Argument");
		exit(0);
	}
	for(int x=0;x<argc;x++){
		printf("%s",argv[x]);
	}
	return 0;
}
