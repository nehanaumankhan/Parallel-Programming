#include <omp.h>
#include <stdio.h>
int main()
{    
    omp_set_dynamic(0);         // force fixed thread count
    omp_set_num_threads(5); 
    #pragma omp parallel
    {
        #pragma omp single
        printf("STATIC SCHEDULE:\n");

        #pragma omp for schedule(static,2)
        for(int n=0; n<10; ++n)
            printf("Thread# %d says %d\n", omp_get_thread_num(),n);
        
        #pragma omp single
        printf("DYNAMIC SCHEDULE:\n");

        #pragma omp for schedule(dynamic,2)
        for(int n=0; n<10; ++n)
            printf("Thread# %d says %d\n", omp_get_thread_num(),n);

    }
    return 0;
}