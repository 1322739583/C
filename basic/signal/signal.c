//
// Created by xzh on 2021/6/14.
//

#include "../basic.h"
#include "signal.h"
#include "sys/types.h"
#include "sys/wait.h"


int test_kill();
void test_signal();
void test_signal2();


static void sig_usr(int signo);

int main(){
    // test_kill();
    test_signal();
}
/**
 * 测试SIGUSR1 SIGUSR2信号
 * 输入：
 * ./a.out
 * 输出：[1] 7216 作业控制shell打印作业编号和进程id
 * 输入：
 * kill -USR1 [pid]
 * 输出：recieved SIGUSER1
 * 输入：
 * kill -USR2 [pid]
 * 输出：recieved SIGUSER2
 * 输入：
 * kill [pid]
 * 输出：
 * 无，程序结束
 */
void test_signal() {
    //signal函数的作用是向内核注册信号。
    if (signal(SIGUSR1,sig_usr)==SIG_ERR)//signal的第二个参数需要传的是void类型（函数指针），所以可以传入函数名（函数指针）
      fprintf(stderr,"can't catch SIGUSR1");
    if (signal(SIGUSR2,sig_usr)==SIG_ERR)
        fprintf(stderr,"can't catch SIGUSR2");
     for(;;)//程序停住好调用kill命令发送信号
        pause();

}

/**
 * 测试SIGTSTP SIGINT信号
 * 输入：
 * 键盘ctrl-c或者ctrl-z
 * 输出：在输出字符串occ sig is [i]中穿插recieved SIGTSTP或者recieved SIGINT

 */
void test_signal2() {
    //signal函数的作用是向内核注册信号。
    if (signal(SIGTSTP,sig_usr)==SIG_ERR)//signal的第二个参数需要传的是void类型（函数指针），所以可以传入函数名（函数指针）
        fprintf(stderr,"can't catch SIGTSTP");
    if (signal(SIGINT,sig_usr)==SIG_ERR)
        fprintf(stderr,"can't catch SIGINTI");
    int i=0;
    //写成下面的死循环也是一样的，只是没有输出效果不好
    while (i<30){
        printf("occ sig is %d\n",i);
        sleep(1);
        i++;
    }

//    for(;;)//程序停住好调用kill命令发送信号
//        pause();


}


/**
 * 信号处理函数
 * @param signo
 */
static void sig_usr(int signo){
    if (signo==SIGUSR1){
        printf("recieved SIGUSER1\n");
    }
    else if (signo==SIGUSR2){
        printf("recieved SIGUSER2\n");
    } else if (signo==SIGTSTP){
        printf("recieved SIGTSTP\n");
    }else if (signo==SIGINT){
        printf("recieved SIGINT\n");
    }else{
        printf("reciived signal %d\n",signo);//这行并没有被调用
    }
}


int test_kill() {
    pid_t pid;
    int state;
    if(!(pid=fork())){//表示成功fork成功返回0
        printf("I am child process,pid=%d\n",pid);
        sleep(3);
        return 0;
    } else{
        printf("send signal to child process,pid=%d\n",pid);
        sleep(1);
        kill(pid,SIGALRM);//kill并发送信号。共31种信号
        wait(&state);
        if (WIFSIGNALED(state)){//WIFSIGNALED 意思是 wait if signaled
            printf("child process recieve signal %d\n",WTERMSIG(state));//wait term signal 等待终端信号的意思，用于获取信号值
        }

    }
}
