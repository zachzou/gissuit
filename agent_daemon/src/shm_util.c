#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include "shm_util.h"

char* get_shm(int iKey, int iSize, int iFlag)
{
key_t key;
int iShmID;
char* sShm;
char sErrMsg[50];

	if ((iShmID = shmget(iKey, iSize, iFlag)) < 0) {
		sprintf(sErrMsg, "shmget %d %d", iKey, iSize);
		perror(sErrMsg);
		return NULL;
	}
	if ((sShm = (char*)shmat(iShmID, NULL ,0)) == (char *) -1) {
		perror("shmat");
		return NULL;
	}
	return sShm;
}

int open_shm(void **pstShm, int iShmKey, int iSize, int iFlag)
{
char* sShm;

	if (!(sShm = get_shm(iShmKey, iSize, iFlag & (~IPC_CREAT)))) {
		if (!(iFlag & IPC_CREAT)) return -1;
		if (!(sShm = get_shm(iShmKey, iSize, iFlag))) return -1;
		
		memset(sShm, 0, iSize);
	}
	*pstShm = sShm;
	return 0;
}
