//Example 
#include <omp.h>
#include <stdio.h>
int main()
{
    int i, n=11; //defined vars => shared among threads
    int sum = 0; //shared variable to hold sum
    #pragma omp parallel for default(shared)
        for (i=0; i<n; i++)
        {
            sum += i;
        }
    printf("sum = %d\n", sum);

    return 0;
}