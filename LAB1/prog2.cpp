//Example Program 02: Parallel Region with num_threads Clause
#include <omp.h>
#include <stdio.h>
int main()
{
#pragma omp parallel num_threads(10)
{
printf("Hello from thread %d out of %d\n",omp_get_thread_num(), omp_get_num_threads());
}
return 0;
}