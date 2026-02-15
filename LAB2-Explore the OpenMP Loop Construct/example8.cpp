#include <stdio.h>
#include <omp.h>
int main() {
int i, n = 8;
#pragma omp parallel private(i)
    {
        #pragma omp for nowait
        for (i = 0; i < n; i++) {
            printf("Thread %d loop i=%d\n", omp_get_thread_num(), i);
        }
        // This may print before other threads finish the loop
        printf("[Outside NoWait Region] Thread %d after loop\n", omp_get_thread_num());
    }
return 0;
}
