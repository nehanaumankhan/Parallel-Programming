//Example 
#include <omp.h>
#include <stdio.h>
int main()
{
    int i, n=6; //defined vars => shared among threads
    int a[6] = {0,0,0,0,0,0}; //array a to hold results
    
    #pragma omp parallel for shared(a)
        for (i=0; i<n; i++)
        {
            a[i] = a[i] + 1;
        }
    for (i=0; i<n; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}