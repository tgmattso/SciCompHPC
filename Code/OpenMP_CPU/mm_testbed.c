/*
**  PROGRAM: Matrix Multiplication test bed
**
**  PURPOSE: This program will test various methods for 
**           multiplying matrices. 
**
**                C  += A * B
**
**           Basic parameters and function prototypes can
**           be found in the include file mm_utils.h
**
**           We test rectangular matrices of two different
**           types: a constant matrix and one called a progression
**           matrix where we modify matrix elements by a progression
**           of matrix index values.
**
**  USAGE:   Run wtihout arguments to use default SIZE set in the
**           mm_utils.h include file ... for example  
**              mm_testbed
**
**           Run with a single argument to generare rectangular matrices 
**           and use fixed ratios of matrix dimensions ... for example
**              mm_testbed   25
**
**           Specify dimensions of matrices A(n,p),B(p,m) and C (n,m)
**           for example for n=23, m=67 and p=213
**              mm_testbed   23 67 213
**
**  HISTORY: Written by Tim Mattson, Feb 2013
*/
#include <stdlib.h>
#include "mm_utils.h"
#define SIZE 300
#define NTRIALS 5

//#define DEBUG    1

//  matrix multiplication test cases
void mm_ijk (int Ndim, int Mdim, int Pdim, TYPE *A, TYPE *B, TYPE *C);
void mm_opt (int Ndim, int Mdim, int Pdim, TYPE *A, TYPE *B, TYPE *C);

int main(int argc, char **argv)
{
   int Ndim, Mdim, Pdim;   /* A[N][P], B[P][M], C[N][M] */
   int Matrix_size;
   TYPE *A, *B, *C; 

// set matrix dimensions and allocate memory for matrices
   if(argc ==2){
      Matrix_size = atoi(argv[1]);
      Ndim = Matrix_size;
      Pdim = 2*Matrix_size;
      Mdim = 3*Matrix_size;
   }
   else if(argc ==4){
      Ndim = atoi(argv[1]);
      Mdim = atoi(argv[2]);
      Pdim = atoi(argv[3]);
   }
   else{
      Ndim = SIZE;
      Pdim = 2*SIZE;
      Mdim = 3*SIZE;
   }

   A    = (TYPE *) malloc(Ndim*Pdim*sizeof(TYPE));
   B    = (TYPE *) malloc(Pdim*Mdim*sizeof(TYPE));
   C    = (TYPE *) malloc(Ndim*Mdim*sizeof(TYPE));

   printf("\n==================================================\n");
   printf(" triple loop, ijk case %d %d %d\n", Ndim, Mdim, Pdim);
   mm_tst_cases(NTRIALS, Ndim, Mdim, Pdim, A, B, C, &mm_ijk);

   printf("\n==================================================\n");
   printf(" Optimized MatMul case %d %d %d\n", Ndim, Mdim, Pdim);
   mm_tst_cases(NTRIALS, Ndim, Mdim, Pdim, A, B, C, &mm_opt);

}
