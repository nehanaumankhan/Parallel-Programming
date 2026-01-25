#include <omp.h>
#include <stdio.h>
int main(){
    //Dynamic threads mean:
    //OpenMP is allowed to change the number of threads at runtime depending on system load.
    //Setting dynamic threads to false means:
    //The number of threads will remain fixed as specified by the programmer.
    omp_set_dynamic(0); // force fixed thread count
    
    omp_set_num_threads(16); //Sets default number of threads; Used only if no num_threads() clause exists
    
    #pragma omp parallel num_threads(10) 
    //This overrides the earlier omp_set_num_threads(16);
    // OpenMP will create 10 threads, not 16
    
    printf("Num threads in parallel region=%d\n", omp_get_num_threads());
    
    return 0;
}