#include <stdio.h>
#include <omp.h>

int main(int argc, const char **argv)
{
    printf("This is the main thread.\n");
    omp_set_dynamic(0);   // Disable dynamic adjustment of threads
    int id;
    #pragma omp parallel private(id) num_threads(6)
    {
        id = omp_get_thread_num();
        #pragma omp single
        {
            printf("Total number of threads: %d\n", omp_get_num_threads());
            printf("In single directive, this is thread #%d\n", id);
        }
        #pragma omp sections
        {
            #pragma omp section
            printf("In section a, this is thread #%d\n", id);

            #pragma omp section
            printf("In section b, this is thread #%d\n", id);

            #pragma omp section
            printf("In section c, this is thread #%d\n", id);
        }
    }
    printf("Back to the main thread. Goodbye!\n");
    return 0;
}
