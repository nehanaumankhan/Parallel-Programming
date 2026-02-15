//Example-3: Shared Clause – All threads can read from and write to vector a.
#include <omp.h>
#include <stdio.h>
int main()
{
    int i, n= 6, a[6] = {1, 1, 1, 1, 1, 1};
    #pragma omp parallel for shared(a)
        for (i=0; i<n; i++)
        {
            a[i] += i;
            printf("Thread %d executes loop iteration %d: a[%d]=%d\n",omp_get_thread_num(), i, i, a[i]);
        }  
    return 0;
}


