#include "shm_util.h"
#ifndef _AGENT_API_H
#define _AGENT_API_H
#define	AGENT_SHM_ID		24555
#define AGENT_MAX_NODE		100

typedef struct
{
	int iUse; //be used ?
	int iIID; //item id
	int iCur; //current value
} ItemNode;

typedef struct
{
	ItemNode astNode[AGENT_MAX_NODE];
} ItemList;

int do_add(int iid,int iVal);

int do_set(int iid,int iVal);
int do_get(int iid,int *piVal);
#endif
