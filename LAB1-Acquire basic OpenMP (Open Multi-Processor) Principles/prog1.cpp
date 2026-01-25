//Example 
#include <omp.h>
#include <stdio.h>
int main()
{
    int i, a, n=6; //defined vars => shared among threads
    
    omp_set_num_threads(4); // Set number of threads to 4
   
    #pragma omp parallel for 
        for (i=0; i<n; i++)
        {
                    a = i + 1;
                    printf("Thread %d: i= %d, a = %d\n", omp_get_thread_num(), i, a);
            }

    return 0;
}