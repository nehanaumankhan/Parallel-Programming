#include <omp.h>
#include <stdio.h>
int main()
{
    int n, i;
    printf("not using the barrier\n");
    #pragma omp parallel
    { 
        i=0;
        #pragma omp for firstprivate(i) nowait
        for(n=0; n<5; ++n)
        {
            printf("thread# %d says %d, this is my iteration# %d\n", omp_get_thread_num(),n,i);
            i++;
        }
        printf("thread# %d says i'm done\n",omp_get_thread_num());
    }
    printf("using the barrier now\n");
    #pragma omp parallel
    {
        i=0;
        #pragma omp for firstprivate(i) lastprivate(i)
        for(n=0; n<5; ++n)
        {
            printf("thread# %d says %d, this is my iteration# %d\n",omp_get_thread_num(),n,i);
            i++;
        }
        
        printf("thread# %d says i'm done\n",omp_get_thread_num());
        #pragma omp single
        printf("value of i is %d\n",i);
         
    } 
    return 0;
}