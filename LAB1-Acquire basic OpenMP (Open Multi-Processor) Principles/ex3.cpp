#include <omp.h>
#include <stdio.h>
int main(){
    omp_set_dynamic(1);
    omp_set_num_threads(6);
    #pragma omp parallel //parallel region 1
    printf("Num threads in dynamic region=%d\n", omp_get_num_threads());

    omp_set_dynamic(0);
    omp_set_num_threads(3);
    #pragma omp parallel //parallel region 2
    printf("Num threads in non-dynamic region=%d\n", omp_get_num_threads());
    
    omp_set_dynamic(1);
    #pragma omp parallel //parallel region 3
        #pragma omp parallel
        printf("Num threads in nesting disabled region=%d\n", omp_get_num_threads());
     printf("\nNEXT PART WITH NESTING ENABLED\n\n");   
    omp_set_nested(1);
    #pragma omp parallel //parallel region 4
        #pragma omp parallel
        printf("Num threads in nested region=%d\n", omp_get_num_threads());
    return 0;
}
