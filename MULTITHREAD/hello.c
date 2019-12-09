#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
int nthreads, tid;

/* Fork a team of threads giving them their own copies of variables */
#pragma omp parallel private(nthreads, tid)
  {

  /* Obtain thread number */
  tid = omp_get_thread_num();
  printf("Hello World from thread = %d\n", tid);

  /* Only master thread does this */
  if (tid == 0) 
    {
    nthreads = omp_get_num_threads();
    printf("Number of threads = %d\n", nthreads);
    }

  /* Only ONE thread does this */
#pragma omp single
  {
    nthreads = omp_get_num_threads();
    printf("Number of threads = %d  (this thread= %d)\n", nthreads,tid);
  }

  }  /* All threads join master thread and disband */

}

/* How to compile this:

gcc hello.c -lm -fopenmp -o hello

* to set the number of thread (in bash)
export OMP_NUM_THREAD=[NN]

*/
