//
//  This is a very a template for a simple version of ping pong ... 
//   The task for a student is to go to the loop over repetitions and 
//
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define VAL 42.         // a value to pass between a pair of nodes
#define NREPS  10.  // Do it this many times so we get a good time value
int main(int argc, char **argv)
{

   int rank, size;
   double t0;
   
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   MPI_Comm_size(MPI_COMM_WORLD, &size);

   if(size <2){    // this program only works if you have two or more nodes
      printf("too few ranks\n");
      exit(-1);
   }

   int bsend = VAL;    // buffer holding value to send
   int brecv = 0;         //  buffer to hold the value received
   MPI_Status stat;   //  Space to hold message status information ... which we usually ignore
   
   if(rank == 0) t0 = MPI_Wtime();   // time the program on node 0

   for(int i=0;i<NREPS; i++){.    // bounce the messages between a pair of node NREPS times
     //****************************************************
     // Insert the message passing code here 
     // Remember the goal is to bounce the message back and forth between the nodes.
     // Check to make sure you get the right answer each time.
     //****************************************************
   }
   
   if(rank == 0){
      double t = MPI_Wtime() - t0;
      double lat = t/(2*NREPS);
      printf(" lat = %f seconds\n",(float)lat);
   }
   MPI_Finalize();
}



 
