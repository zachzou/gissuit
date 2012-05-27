
#ifndef _SHM_UTIL_H
#define _SHM_UTIL_H

#include <sys/ipc.h>
#include <sys/shm.h>

char* get_shm(int iKey, int iSize, int iFlag);
int open_shm(void **pstShm, int iShmKey, int iSize, int iFlag);

#endif
