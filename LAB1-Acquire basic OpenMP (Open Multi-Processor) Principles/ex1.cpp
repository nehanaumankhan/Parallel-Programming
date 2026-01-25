#include <omp.h>
#include <stdio.h>
int main(){
    #pragma omp parallel 
    printf("Num threads in parallel region=%d\n", omp_get_num_threads());
    /*-- End of parallel region --*/
    return 0;
}/*-- End of Main Program --*/