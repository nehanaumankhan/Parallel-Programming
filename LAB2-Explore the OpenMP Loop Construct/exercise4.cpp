#include <omp.h>
#include <stdio.h>
int main(int argc, char* argv[])
{ 
    int N=100;
    double a[N], sum=0.0; 
    int i;
    #pragma omp parallel shared(a) private(i)
    {
        #pragma omp single
        printf("Number of threads = %d\n",omp_get_num_threads());
        
        #pragma omp for
        for(i=0;i<N;i++) a[i]=i+1;

        #pragma omp for reduction(+:sum)
        for(i=0;i<N; i++) sum=sum+a[i]; 
    } 
    // sums of all threads are added up into one variable
    printf("Sum = %2.1f\n",sum);

    return 0;
}