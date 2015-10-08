#include <stdio.h>
#include <pthread.h>

void *thread_routine(void* arg)
{
  printf("Hello from new thread!\n");
  return NULL;
}

int main()
{
  printf("Hello from main thread!\n");

  pthread_t tid;
  int error;

  if(error = pthread_create(&tid, NULL, thread_routine, NULL)) {
    printf("%d\n", strerror(error));
  }
  pthread_join(tid, NULL);
}
