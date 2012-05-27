#include <stdio.h>
#include "agent_api.h"
static ItemList *pstItem=NULL;

int show_all_item()
{
	int i;
	
	i=0;
	while(1)
	{
		if (i>=AGENT_MAX_NODE) break;
		if (pstItem->astNode[i].iUse == 0) break;
		
		printf("item: %d value: %d\n", pstItem->astNode[i].iIID, pstItem->astNode[i].iCur);
		i++;
	}
	
	return 0;
}

int search_item_id(ItemList *pstItem,int item,int *piPos)
{
	int i=0;
	*piPos=0;
	while(pstItem->astNode[i].iUse)
	{
		if(pstItem->astNode[i].iIID==item)
		{
			*piPos=i;
			return 1;
		}
		++i;
		//if(i>AGENT_MAX_NODE)return -1;
		if(i>=AGENT_MAX_NODE)return -1;
	}
	
	//if(!*piPos) *piPos=i;
	*piPos = i;
	
	return 0;
}

int do_add(int item,int iValue)
{
	int itemPos, iRet;
	
	if (!pstItem && (open_shm((void **)&pstItem, AGENT_SHM_ID, sizeof(ItemList), 0666)) < 0)
	{
		//printf("can not get shm ...continue!\n");
		//sleep(5);
		return -1;
	}
	
	iRet = search_item_id(pstItem,item,&itemPos);
	
	if(!iRet)//返回0 item不存在，返回1 item存在
	{
		pstItem->astNode[itemPos].iUse=1;
		pstItem->astNode[itemPos].iIID=item;
		pstItem->astNode[itemPos].iCur=iValue;
	}
	else if(iRet==-1)
	{
		printf("out of memery");
		return -1;
	}
	else
	{
		pstItem->astNode[itemPos].iCur+=iValue;
	}
	return 0;
}
int do_set(int item,int iValue)
{
	int itemPos, iRet;
	
	if (!pstItem&&open_shm((void **)&pstItem, AGENT_SHM_ID, sizeof(ItemList), 0666) < 0)
	{
		//printf("can not get shm ...continue!\n");
		//sleep(5);
		return -1;
	}
	
	iRet = search_item_id(pstItem,item,&itemPos);
	
	if(!iRet)//返回0 item不存在，返回1 item存在
	{
		pstItem->astNode[itemPos].iUse=1;
		pstItem->astNode[itemPos].iIID=item;
		pstItem->astNode[itemPos].iCur=iValue;
	}
	else if(iRet==-1)
	{
		printf("out of memery");
		return -1;
	}
	else
	{
		pstItem->astNode[itemPos].iCur=iValue;
	}
	return 0;
}
int do_get(int item,int *piValue)
{
	int itemPos, iRet;
	
	if (!pstItem&&open_shm((void **)&pstItem, AGENT_SHM_ID, sizeof(ItemList), 0666) < 0)
	{
		//printf("can not get shm ...continue!\n");
		//sleep(5);
		return -1;
	}
	
	iRet = search_item_id(pstItem,item,&itemPos);
	
	if(!iRet)//返回0 item不存在，返回1 item存在
	{
		*piValue = 0;
		return 1;
	}
	else if(iRet==-1)
	{
		printf("out of memery");
		*piValue = 0;
		return -1;
	}
	else
	{
		*piValue = pstItem->astNode[itemPos].iCur;
	}
	return 0;
}
