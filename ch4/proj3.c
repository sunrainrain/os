#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define N_LIST   (sizeof(original_list)/sizeof(int))
#define usec_elapsed(s,e)  (1000000 * ((e).tv_sec-(s).tv_sec) + ((e).tv_usec - (s).tv_usec)) 

int sum; // this data is shared by the thread(s)
void *runner(void *param) //threads call this function
int original_list[] = {7, 12, 19, 3, 18, 4, 2, 6, 15, 8};  //Assume there are even numbers

int *listncopy(int *dst, int *src, int n)
{
	for(i = 0; i < n; i++)
	{
		dst[i] = src[i];
	}
	return dst;
}

int main(int argc, char *argv[])
{	
	int mylist[N_LIST]; 

	pthread_t tid; //the thread identifier
	pthread_attr_t attr; // set of thread attributes

	//set the default attrebutes of the thread
	pthread_attr_init(&attr);

	//create the thread
	pthread_create(&tid, &attr, runner, argv[1]);

	//wait for the thread to exit
	pthread_join(tid, NULL);
	
	printf("X1079512 sum = %d\n", sum);
}

//the thread will execute in this function
void *runner(void *param)
{
	int i;
	int upper = atoi(param);
	sum = 0;

	for (i = 1; i <= upper; i++)
	{
		sum += i;
		pthread exit(0);
	}
}
