#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

int main(){
	key_t key=ftok("shmemory",60);
	int shmid=shmget(key,1024,0);
	char *str=(char*)shmat(shmid,(void*)0,0);
	printf("The retrieved data is:%s",str);
	shmdt(str);
	shmctl(shmid,IPC_RMID,NULL);
	exit(0);
}
