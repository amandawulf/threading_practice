#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_routine(void *args)
{
  int *lucky_number = malloc(sizeof(int));
  *lucky_number = 7;
  return lucky_number;
}

int main()
{
  int *lucky_number;

  printf("Hello, my lucky number is: \n");

  pthread_t tid;
  pthread_create(&tid, NULL, thread_routine, NULL);
  pthread_join(tid, (void **) &lucky_number);
  
  printf("%d\n", *lucky_number);
}
