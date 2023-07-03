#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>        
#include <sys/mman.h>
#include <unistd.h>

int main()
{
  int fd, i=0,nloop=1000,zero=0,*ptr;
  sem_t *mutex;

  //파일을 열고 메모리와 매핑한다.
  fd = open("log.txt",O_RDWR|O_CREAT,S_IRWXU);
  write(fd,&zero,sizeof(int));
  ptr = mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  close(fd);
  /* 세마포어를 생성화고 초기화 한다. */
  sem_unlink("my_sem");
  if((mutex = sem_open("my_sem", O_CREAT|O_EXCL, 0000700, 1)) == SEM_FAILED)
    {
      perror("semaphore initilization");
      exit(0);
    }
  if (fork() == 0) { /* child process*/
    for (i = 0; i < nloop; i++) {
      sem_wait(mutex);
      printf("child: %d\n", (*ptr)++);
      sem_post(mutex);
    }
    exit(0);
  }
  /* 부모 프로세스*/
  for (i = 0; i < nloop; i++) {
    sem_wait(mutex);
    printf("parent: %d\n", (*ptr)++);
    sem_post(mutex);
  }
  sem_unlink("my_sem");
//   sem_clo
  exit(0);
}