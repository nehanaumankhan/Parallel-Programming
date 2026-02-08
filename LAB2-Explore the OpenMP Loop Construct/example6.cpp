//Example-6: Lastprivate Clause – This clause makes the sequentially last value of variable a outside the parallel region
#include <stdio.h>
#include <omp.h>
int main() {
    int i, n = 6;
    int a = -1;
    #pragma omp parallel for private(i) lastprivate(a) 
        for (i = 0; i < n; i++) {
            a = i + 1;
            printf("Thread %d executes loop iteration %d, a=%d\n", omp_get_thread_num(), i, a);
        }
    printf("Value of a after loop: a=%d\n", a);
    return 0;
}
