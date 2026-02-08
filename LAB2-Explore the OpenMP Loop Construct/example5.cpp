//Example-5: Firstprivate Clause Whatever value the variable has before entering 
//the parallel region, when it is declared as firstprivate, OpenMP assigns a
//separate copy of that variable to each thread, initialized with that original value.
#include <stdio.h>
#include <omp.h>
int main() {
    int i, indx = 4;
#pragma omp parallel private(i) firstprivate(indx)
{
    indx += omp_get_thread_num();
    printf("Thread %d: indx=%d\n", omp_get_thread_num(), indx);
}
return 0;
}