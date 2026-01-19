//Example Program 01: Basic Parallel Region
#include <omp.h>
#include <stdio.h>
int main()
{
#pragma omp parallel
{
printf("The parallel region is executed by thread %d\n",omp_get_thread_num());
//omp.h have this function implementation & omp_get_thread_num() returns the ID 
//(number) of the current thread executing inside the parallel region.
}
return 0;
}