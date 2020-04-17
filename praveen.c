#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int global[2];

void *sum_thread(void *arg)
{
	int n1,n2,sum;
	n1=global[0];
	n2=global[1];
	sum = n1+n2;

	printf("N1 + N2 = %d\n",sum);

	return NULL;

}

int main()
{
	printf("First Number:");
	scanf("%d",&global[0]);

	printf("Second Number:");
	scanf("%d",&global[1]);



	pthread_t tid_sum;
	pthread_create(&tid_sum,NULL,sum_thread,global);
	pthread_join(tid_sum,NULL);

	return 0;
}
