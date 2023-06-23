#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// gcc는 일부 os에서 -pthread플래그 없이 pthread 라이브러리를 링크하도록 하고 있지만,
// 명시적으로 표시해주는 것이 안전하다.
// gcc test.c -pthread
void *mythread(void *arg) {
	int m = (int)(*(int*)arg);
	printf("%d\n", m);
	return (void *) ((int *)arg + 1);
}

void	assert(int cond)
{
	if (!cond)
	{
		printf("assert error\n");
		exit(1);
	}
}

// void	my_pthread_mutex_init(pthread_mutex_t *mutex) {
// 	int rc = pthread_mutex_init(&mutex, NULL);
// 	assert(rc == 0);
// }

// void	my_pthread_mutex_lock(pthread_mutex_t *mutex) {
// 	int rc = pthread_mutex_lock(mutex);
// 	assert(rc == 0);
// }

// pthread_mutex_unlock(pthread_mutex_t *mutex);
// pthread_mutex_destroy()

int main(int argc, char *argv[]) {
	pthread_t p;
	int rc, m;
	int data = 2;
	pthread_create(&p, NULL, mythread, (void *) &data);
	pthread_join(p, (void **) &m);
	printf("returned %d\n", m);
	return 0;
}

