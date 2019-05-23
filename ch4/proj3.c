#include <pthread.h>
#include <stdio.h>
//#include <stdlib.h >
//#include <sys/time,h>
#define N_LIST   (sizeof(original_list)/sizeof(int))
#define usec_elapsed(s,e)  (1000000 * ((e).tv_sec-(s).tv_sec) + ((e).tv_usec - (s).tv_usec)) 

int sum; // this data is shared by the thread(s)
void *runner(void *param); //threads call this function
int original_list[] = {7,12,19,3,18,4,2,6,15,8};  //Assume there are even numbers

struct timeval{
	long tv_sec;
	long tv_usec;
};

struct timeval start, end;
unsigned long usec;

int *listncopy(int *dst, int *src, int n)
{
	for(int i = 0; i < n; i++)
	{
		dst[i] = src[i];
	}
	return dst;
}

void do_sort(char *id, int *first, int n)
{
	print_list(id, "Sub-Old", first, n);
	gettimeofday(&start, NULL);
	
	//do sorting

	gettimeofday(&end, NULL);
	print_list(id, "Sub-New", first, n);
	
	printf("%s spent %ld usec\n", id, usec_elapsed(start, end));
	return usec_elapsed(start, end);
}


int main(int argc, char *argv[])
{	
	int mylist[N_LIST];
 
	listncopy(mylist, original_list, N_LIST);

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
	int upper = atoi(param);
	sum = 0;

	for (int i = 1; i <= upper; i++)
	{
		sum += i;
	}
	pthread_exit(0);
}
