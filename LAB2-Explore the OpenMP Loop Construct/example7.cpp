#include <stdio.h>
#include <omp.h>
int main() {
    int i, n = 10, chunk = 2;
    float a[10], b[10], result = 0.0f;
    for (i = 0; i < n; i++) {
        a[i] = i * 1.0f; //a = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0}
        b[i] = i * 2.0f; //b = {0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0}
    }
    #pragma omp parallel for default(shared) private(i) schedule(static,chunk) reduction(+:result)
        for (i = 0; i < n; i++) {
        result = result + (a[i] * b[i]);
        }
    printf("Final result = %.1f\n", result); 
return 0;
}
