#include "agent_api.h"
#include "shm_util.h"
#include <stdio.h>

int main(int argc, char* argv[]){

    char* pstItem;

	if (open_shm((void **)&pstItem, AGENT_SHM_ID, sizeof(ItemList), 0666) < 0){
        open_shm((void**)&pstItem, AGENT_SHM_ID, sizeof(ItemList), 0666|IPC_CREAT);
    }
    do_add(1, 1);
    do_add(1, 1);
    do_add(1, 1);

    int rval;
    do_get(1, &rval);
    fprintf(stderr, "rval=%d", rval);

    return 0;
}
