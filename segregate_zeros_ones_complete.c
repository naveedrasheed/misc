/******************************************************************************

                            Problem Statement
Move all 0s before all 1s, in place, in an integer array with million elements 
of 0s and 1s mixed up.

*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include <assert.h>

#define LENGTH 100000000

void populate_data(int *A, long N)
{
    srand(time(0));

    for (long i = 0; i < N; i++)
    {
        A[i] = rand() % 2;
    }
}

void print(int *A, long N)
{
    printf("{");

    for (long i = 0; i < N; i++)
    {
        printf("%d, ", A[i]);
    }

    printf("}\r\n");
}

long get_zeros_count(int *A, long N)
{
    long zero_count = 0;

    for (long i = 0; i < N; i++)
    {
        if (!A[i])
        {
            zero_count++;
        }
    }

    printf("Zeros = %ld\r\n", zero_count);

    return (zero_count);
}

int test(int *A, long N, long zero_count)
{
    int result = 1;

    for (long i = 0; i < zero_count; i++)
    {
        if (A[i] != 0)
        {
            result = 0;
            break;
        }
    }

    for (long i = zero_count; i < N; i++)
    {
        if (A[i] != 1)
        {
            result = 0;
            break;
        }
    }

    return (result);
}

void move_inplace(int *A, long N)
{
	long j = N;

    if (N == 1) return;

    for (long i = 0; i < N; i++)
    {
        if (A[i] && i < j)
        {
            while((A[--j] == 1) && (i < j));

            A[i] = 0;
            A[j] = 1;
        }
        else if (i >= j)
        {
            break;
        }
    }
}

int main()
{
    int A[LENGTH]
    /*
    = {1, 0, 1, 1, 1, 1, 0, 0, 1, 1}
    */
    ;
    long zero_count;

    populate_data(A, LENGTH);
// 	print(A, LENGTH);

 	zero_count = get_zeros_count(A, LENGTH);

 	move_inplace(A, LENGTH);
// 	print(A, LENGTH);

	assert(test(A, LENGTH, zero_count) == 1);

	printf("\r\nSuccess");

    return 0;
}
