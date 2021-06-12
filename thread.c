#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void* myfunc(void* args){
  printf("hello\n");
  return NULL;
}
int main ( ){
  pthread_t th;
  pthread_create(&th,NULL,myfunc,NULL);
  //printf("create thread...");
  pthread_join(th,NULL);
  return 0;
}

