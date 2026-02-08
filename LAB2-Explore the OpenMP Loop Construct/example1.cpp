#include <omp.h>
#include <stdio.h>
int main()
{
    int i, n=6; //initialized = shared; only defined = private 
    omp_set_num_threads(6);
    #pragma omp parallel shared(n) private(i)
    {
        #pragma omp for
            for (i=0; i<n; i++)
            printf("Thread %d executes loop iteration %d\n",omp_get_thread_num(),i);
    }
    return 0;
}