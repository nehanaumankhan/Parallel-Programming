#include <omp.h>
#include <stdio.h>
int main()
{
    int i, sum = 0;
    #pragma omp parallel private(i) shared(sum)
    {
        #pragma omp for
        for(i=0; i<=10; ++i){
            #pragma omp atomic
            sum += i;
        }
    }
    printf("Sum of 1 through 10 is %d\n", sum);
    return 0;
}