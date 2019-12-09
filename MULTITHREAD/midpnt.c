#include <stdio.h>
#include <math.h>
#include <time.h>
#include <omp.h>


double func1(double x);

double FTRUE = 1 - 1/2.718281828;


int main(int argc, char **argv)
{
  double x,y, sum, err, dx, a, b, ftru, t0,t1;
  int i,j,k,N,in;

  t0 = omp_get_wtime();

  // how many bins?
  N = atoi(argv[1]);
  
  // midpoint rule
  b = 1;
  a = 0;
  ftru = FTRUE;

  dx = (b-a)/N;
  sum = 0;     
  for(i=1;i<=N;++i)
    {
      sum += func1(a + (i-0.5)*dx);
    }
  sum *= dx;
  err = (sum-ftru)/ftru;
  t1 = omp_get_wtime();
  printf("X0 %d %e %e %e %f\n",N,dx,sum,err,t1-t0);

  printf("That took %f seconds\n",t1-t0);
  
}

double func1(double x)
{
  return exp(-x);
}


