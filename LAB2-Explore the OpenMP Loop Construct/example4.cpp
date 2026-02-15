#include <stdio.h>
#include <omp.h>
int main() 
{
    int i, n = 10, sum = 0;
        #pragma omp parallel for default(shared) private(i)
        for (i = 0; i < n; i++) sum += i;
        printf("sum=%d (may be wrong due to race)\n", sum);
return 0;
}
//Keeping sum as private results in wrong output because each thread has its own copy of sum,
// so the updates made by one thread are not visible to others
// #include <stdio.h>
// #include <omp.h>

// int main() 
// {
//     int i, n = 6, sum = 0;
//         #pragma omp parallel for private(i, sum)
//         for (i = 0; i < n; i++) {
//             // WARNING: sum update is NOT safe here (race condition)
//             sum += i;
//         }
//         printf("sum=%d (may be wrong due to race)\n", sum);
// return 0;
// }