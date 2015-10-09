#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_routine(void *args)
{
  int *lucky_number;
  lucky_number = (int *)args;
  printf("%d\n", *lucky_number);
}

int main()
{
  int *lucky_number;
  *lucky_number = 7;

  printf("Hello, my lucky number is: \n");

  pthread_t tid;
  pthread_create(&tid, NULL, thread_routine, lucky_number);
  pthread_join(tid, (void **) &lucky_number);
}
