#include <omp.h>
#include <stdio.h>
int main()
{
    int n, i;
    printf("NOT USING BARRIER\n");
    #pragma omp parallel
    { 
        i=0;
        #pragma omp for firstprivate(i) nowait    //nowait -> No Barrier
        for(n=0; n<10; ++n)
        {
            printf("[No Barrier] thread# %d says %d, this is my iteration# %d\n", omp_get_thread_num(),n,i);
            i++;
        }
    printf("[No Barrier] thread# %d says i'm done\n",omp_get_thread_num());
    }
    printf("USING THE BARRIER NOW\n");
    #pragma omp parallel
    {
        i=0;
        #pragma omp for firstprivate(i) lastprivate(i) // No nowait -> Implicit Barrier
        for(n=0; n<10; ++n)
        {
            printf("[With Barrier] thread# %d says %d, this is my iteration# %d\n", omp_get_thread_num(),n,i);
            i++;
        }
        printf("[With Barrier] thread# %d says i'm done\n",omp_get_thread_num());
        #pragma omp single
        printf("[With Barrier] value of i is %d\n",i); 
    }       
    return 0;
}