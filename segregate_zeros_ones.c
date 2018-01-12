/******************************************************************************

                            Problem Statement
Move all 0s before all 1s, in place, in an integer array with million elements 
of 0s and 1s mixed up.

*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include <assert.h>

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
