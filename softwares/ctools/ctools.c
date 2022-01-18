//
// Created by xzh on 2022/1/18.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "memory.h"
#include "unistd.h"
#include "error.h"
#include "errno.h"
#include "time.h"
#include <sys/types.h>
#include <sys/wait.h>

void monitorByPID(int process_id) {
    int status;
    pid_t return_pid = waitpid(process_id, &status, WNOHANG); /* WNOHANG def'd in wait.h */
    if (return_pid == -1) {// error
        printf("发生错误");
    } else if (return_pid == 0) {// child is still running */
        printf("正在运行");
    } else if (return_pid == process_id) { // child is finished. exit status in   status */
        printf("程序结束");
    }
}


void welcome() {
    printf("-----------------");
    printf("");
}

void getPid(){
    char line[1024];
    FILE * command = popen("pidof ...","r");

    fgets(line,1024,command);

    pid_t pid = strtoul(line,NULL,10);
    pclose(command);
}



int main(){
    monitorByPID(1);
    return 0;
}