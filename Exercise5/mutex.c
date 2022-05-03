#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Functions
void *sumlines(void *arg);

int c = 0;      // Count, used for threads.
int res = 0;    // Total sum of numbers stored in a matrix.
int sarray;     // Size of array.
// This variable tarray can be used to threads to calculate and
// return a sum of numbers for each line of matrix.
int *tarray;
int **arr;      // Matrix.

// Initialize Thread Mutex.
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(void) {
    // Read numbers for size of matrix.
    scanf("%d", &sarray);
    // Allocate the memory for matrix and array.
    arr = (int **)malloc(sizeof(int *) * sarray);
    for (int i = 0; i < sarray; i++)
        arr[i] = (int *)malloc(sizeof(int) * sarray);
    tarray = (int *)malloc(sizeof(int) * sarray);
    // Read numbers and store to matrix.
    for (int i = 0; i < sarray; i++)
        for (int j = 0; j < sarray; j++)
            scanf("%d", &arr[i][j]);
    /*
    Create threads for calculating a sum of numbers from matrix. 
    A thread can be used to read numbers on the line of matrix and
    calculate and return a sum of numbers. Next thread will read
    numbers located on the next line of matrix and so on.
    At the end of thread, we can print a total sum of numbers
    stored in a matrix.
    */
    pthread_t threads[sarray];
    for (int i = 0; i < sarray; i++) {
        if (pthread_create(&(threads[i]), NULL, sumlines, NULL)) {
            printf("Failed creating threads...\n");
        }
    }
    // Run threads for calculating.
    for (int i = 0; i < sarray; i++) {
        pthread_join(threads[i], NULL);
    }
    // Print the result in total sum of numbers stored in a matrix.
    printf("%d\n", res);
    return 0;
}

// Thread to calculate numbers at each line of a matrix.
// Next thread after finishing executation of thread will
// calculate the numbers at next line of matrix.
void *sumlines(void *arg) {
    // Lock the Mutex
    pthread_mutex_lock(&mutex);
    int resl = 0;
    for (int k = 0; k < sarray; k++) {
        resl = resl + arr[c][k];
        res = res + arr[c][k];
    }
    tarray[c] = resl;
    c = c + 1;
    // Unlock the Mutex after returning.
    pthread_mutex_unlock(&mutex);
    return arg;
}
