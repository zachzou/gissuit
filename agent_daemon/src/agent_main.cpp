/*========================================================================
#   FileName: agent_main.cpp
#     Author: zach
#      Email: 40919212@qq.com
#   HomePage: http://
#    Created: 2012-05-05
# LastChange: 2012-05-12 22:38:32
========================================================================*/
#include <iostream>
#include <string>
#include <sys/shm.h>
#include <sys/ipc.h>

using namespace std;


#define SHM_KEY 0x123456
#define MAX_

typdef struct {
    string      hostip;
    int32_t     port;
    int32_t     shm_key;    //共享内存的key
    int32_t     interval;   //上报时间间隔, 默认10秒上报一次
}G_VAR;
G_VAR g_var;

typedef struct {
    char func_name[32]; //函数名
    char func_count;    //调用计数
}

int init_conf(){

    return 0;
}

int init_data(){
    
    if (g_var.shm_key=shmget(SHM_KEY, ))
    if (shmget(SHM_KEY, IPC_CREAT))
}

int main(int argc, char* argv[]){

    init_conf();

    init_data();

    return 0;
}
