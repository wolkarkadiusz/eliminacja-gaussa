#include <stdio.h>
#include "gauss.h"

int main() {
    int n = 3;

    double r0[] = {2, 1, -1};
    double r1[] = {-3, -1, 2};
    double r2[] = {-2, 1, 2};

    double *A[] = {r0, r1, r2};
    double b[] = {8, -11, -3};
    double x[3];

    gaussian_elimination(A, b, n);
    back_substitution(A, b, x, n);

    printf("Rozwiązanie układu:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }

    return 0;
}
