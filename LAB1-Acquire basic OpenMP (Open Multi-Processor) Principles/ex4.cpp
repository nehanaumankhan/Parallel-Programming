#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel
    {
        while (1) {
            // infinite loop
            printf("Thread %d is running\n", omp_get_thread_num());
        }
    }
    return 0;
}
