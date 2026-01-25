#include <omp.h>
#include <stdio.h>
int main()
{
    int i, n = 6;
    int a = -1;

    #pragma omp parallel lastprivate(a)
            for(i = 0; i < n; i++)
            {
                a = i + 1;
            }
    printf("a = %d\n", a);
        return 0;
}
