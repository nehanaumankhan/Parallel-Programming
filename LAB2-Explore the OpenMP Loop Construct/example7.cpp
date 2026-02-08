#include <stdio.h>
#include <omp.h>
int main() {
    int i, n = 10, chunk = 2;
    float a[10], b[10], result = 0.0f;
    for (i = 0; i < n; i++) {
        a[i] = i * 1.0f;
        b[i] = i * 2.0f;
    }
    #pragma omp parallel for default(shared) private(i) schedule(static,chunk) reduction(+:result)
        for (i = 0; i < n; i++) {
        result = result + (a[i] * b[i]);
        }
    printf("Final result = %.1f\n", result);
return 0;
}
