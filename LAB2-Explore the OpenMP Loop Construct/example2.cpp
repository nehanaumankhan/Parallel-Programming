//Example-2: Private Clause – Each thread has a local copy of variables i and a.
#include <omp.h>
#include <stdio.h>
int main()
{
    int i, n= 6, a;  
    #pragma omp parallel for private(i,a)
        for (i=0; i<n; i++)
        { 
            a = i+1;
            printf("Thread %d has a value of a = %d for i = %d\n",omp_get_thread_num(),a,i);
        } 
    return 0;
}


