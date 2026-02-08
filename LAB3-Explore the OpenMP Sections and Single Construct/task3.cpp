#include <stdio.h>
#include <omp.h>
int main() {
    int A = 2, B = 1, C = 0;
    omp_set_dynamic(0);
    omp_set_num_threads(4);
    #pragma omp parallel shared (A,B) private (C)
    {
        int tid = omp_get_thread_num(); 
        C = A + tid;
        #pragma omp barrier // Ensure all threads have computed C before proceeding
        if(tid % 2 == 0) {
            A = A + C;}
        else{
            B = B + C;
        }
        #pragma omp barrier // Ensure all threads have updated A and B before proceeding
        #pragma omp single
        {
            A = A + B;
        }
            printf("Thread %d - A = %d, B = %d, C = %d\n", tid, A, B, C);
        }

    printf("After the parallel region: A = %d, B = %d\n", A, B);

    return 0;
}