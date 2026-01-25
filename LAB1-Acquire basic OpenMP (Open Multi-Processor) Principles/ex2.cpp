#include <omp.h>
#include <stdio.h>
int main(){
    //Dynamic threads means dynamic adjustment of the number of threads
    //Setting dynamic threads=0 means the number of threads will remain fixed as specified by the programmer.
    omp_set_dynamic(0);         // force fixed thread count
    omp_set_num_threads(16);    //Sets default number of threads;Used only if no num_threads() clause exists
    #pragma omp parallel num_threads(10) //Method overriding - OpenMP will now create 10 threads, not 16
    printf("Num threads in parallel region=%d\n", omp_get_num_threads());
    return 0;
}