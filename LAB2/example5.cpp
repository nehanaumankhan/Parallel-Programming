#include <omp.h>
#include <stdio.h>
int main()
{
    int i;
    int indx = 4;
    omp_set_num_threads(4);

    #pragma omp parallel firstprivate(indx)
        {
            indx += omp_get_thread_num();
            printf("Thread %d: indx = %d\n", omp_get_thread_num(), indx);
        }
        return 0;
}
