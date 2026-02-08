#include <stdio.h>
#include <omp.h>
int main()
{
    int i, n = 10, chunk = 2;
    float a[10], b[10], result = 0.0f;
    #pragma omp parallel for schedule(static, chunk) private(i)
    for(i = 0; i < n; i++)
    {
        a[i] = i * 1.0f;
        b[i] = i * 2.0f;
    }
    omp_set_num_threads(4);
    printf("Result = %f\n", result);
}