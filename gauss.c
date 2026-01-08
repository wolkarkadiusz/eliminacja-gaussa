#include <stdio.h>
#include <math.h>
#include "gauss.h"

// Wybór pivota
void choose_pivot(double **A, double *b, int n, int k) {
    int max = k;

    for (int i = k + 1; i < n; i++) {
        if (fabs(A[i][k]) > fabs(A[max][k])) {
            max = i;
        }
    }

    if (max != k) {
        double *tmp = A[k];
        A[k] = A[max];
        A[max] = tmp;

        double tb = b[k];
        b[k] = b[max];
        b[max] = tb;
    }
}

// Eliminacja Gaussa
// Sprowadzenie do postaci górnotrójkątnej
void gaussian_elimination(double **A, double *b, int n) {
    for (int k = 0; k < n - 1; k++) {
        choose_pivot(A, b, n, k);

        for (int i = k + 1; i < n; i++) {
            double m = A[i][k] / A[k][k];
            for (int j = k; j < n; j++) {
                A[i][j] -= m * A[k][j];
            }
            b[i] -= m * b[k];
        }
    }
}
