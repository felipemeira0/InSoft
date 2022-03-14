#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define THREADS 3

int nums = 0;
int *numarray;

void *findLowestNumber(void *a);
void *findHighestNumber(void *a);
void *findAverageNumber(void *a);

// Use Mutex to improve runtime
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int main() {
	// Create thread variable
	pthread_t th[THREADS];
	int re[THREADS];
	int pa[THREADS];
	
	// Numbers Input
	scanf("%d", &nums);
	
	numarray = malloc(sizeof(int) * nums);
	
	for (int i = 0; i < nums; i++)
		scanf("%d", &numarray[i]);
		
	for (int i = 0; i < THREADS; i++)
		pa[i] = i;
	
	// Next, create a funcionality of all three threads
	// Thread A - Calculating and returning the lowest number
	re[0] = pthread_create(&(th[0]), NULL, findLowestNumber,
		(void *)(&(pa[0])));
	
	// Thread B - Calculating and returning the highest number
	re[1] = pthread_create(&(th[1]), NULL, findHighestNumber,
		(void *)(&(pa[1])));
		
	// Thread C - Calculating and returning the average number
	re[2] = pthread_create(&(th[2]), NULL, findAverageNumber,
		(void *)(&(pa[2])));
	
	// Use three threads to calculate	
	for (int i = THREADS; i > 0; i--)
		pthread_join(th[i-1], NULL);
	
	// Three threads will print the result and finish the program
	
	return 0;
}

void *findLowestNumber(void *a) {
	pthread_mutex_lock(&mutex1);
	int *arr = numarray;
	int lowest = arr[0];
	int res;
	for (int i = 0; i < nums; i++)
		if (arr[i] < lowest)
			lowest = arr[i];
			
	res = lowest;
	printf("The minimum value is %d\n", res);

	pthread_mutex_unlock(&mutex1);
	return 0;
}

void *findHighestNumber(void *a) {
	pthread_mutex_lock(&mutex1);
	int *arr = numarray;
	int highest = arr[0];
	int res;
	for (int i = 0; i < nums; i++)
		if (arr[i] > highest)
			highest = arr[i];

	res = highest;
	printf("The maximum value is %d\n", res);
	
	pthread_mutex_unlock(&mutex1);
	return 0;
}

void *findAverageNumber(void *a) {
	pthread_mutex_lock(&mutex1);
	int avg = 0;
	int tot = 0;
	int *arr = numarray;
	int res;
	for (int i = 0; i < nums; i++)
		tot = tot + arr[i];
	
	avg = (tot / nums);
	res = avg;
	printf("The average value is %d\n", avg);
	
	pthread_mutex_unlock(&mutex1);
	return 0;
}
