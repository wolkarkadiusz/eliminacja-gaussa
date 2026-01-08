#include <stdio.h>
#include "gauss.h"

int main() {
    int n = 3;

    double r0[] = {2, 1, -1};
    double r1[] = {-3, -1, 2};
    double r2[] = {-2, 1, 2};

    double *A[] = {r0, r1, r2};
    double b[] = {8, -11, -3};

    gaussian_elimination(A, b, n);

    printf("Macierz po eliminacji Gaussa:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.3f ", A[i][j]);
        }
        printf("| %8.3f\n", b[i]);
    }

    return 0;
}
