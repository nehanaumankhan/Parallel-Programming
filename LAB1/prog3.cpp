//Example Program 03: Fixed Thread Control
#include <omp.h>
#include <stdio.h>
int main()
{
omp_set_dynamic(0);//Turns off automatic thread adjustment (OpenMP must use the number we ask for).
omp_set_num_threads(16); //Sets the default number of threads to 16.
    #pragma omp parallel
    {
        #pragma omp single
        printf("Parallel Region A: total threads = %d\n",omp_get_num_threads());
    }
    #pragma omp parallel num_threads(3)
    {
        #pragma omp single
        printf("Parallel Region B: total threads = %d\n",omp_get_num_threads());
    }
return 0;
}