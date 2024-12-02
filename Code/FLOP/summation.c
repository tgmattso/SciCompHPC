/*

NAME:   
   summation

Purpose: 
   Create an array of numbers and explore floating point 
   arithmetic issues as you sum the array
   
Usage:
   This program depends on a set of functions from the file
   UtilityFunctions.c.   For reasons of pedagogy, do not look
   at the functions in UtilityFunctions.c. Treat it as a block box.

        gcc summation.c UtilityFunctions.c

History: 
   Written by Tim Mattson, 9/2023.

*/
#include <stdio.h>
#include <stdlib.h>
#include "UtilityFunctions.h"  // where FillSequence comes from

#define N 100000  //length of sequence of numbers to work with  

//============================================================================

int main ()
{
   float seq[N];    //Sequence to sum, statically defined to keep the code simple
   float True_sum;  //The best estimate of the actual sum
   float sum = 0.0f;

   FillSequence(N, seq, &True_sum); // populate seq with N random values > 0

   #pragma omp parallel for reduction(+:sum)
   for(int i=0; i<N; i++)sum += seq[i];

   printf(" Sum = %f, Estimated sum = %f\n",sum,True_sum);

}
