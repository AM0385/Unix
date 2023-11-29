#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<sys/ipc.h>

int main(){
	key_t key =ftok("shmemory",60);
	int shmid=shmget(key,1024,0666|IPC_CREAT);
	char *str= (char*)shmat(shmid,(void*)0,0);
	printf("Enter the data to be written inide\n");
	gets(str);
	printf("Data has been written\n");
	shmdt(str);
	exit(0);
}
