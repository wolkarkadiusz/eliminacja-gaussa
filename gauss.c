#include <stdio.h>
#include <math.h>
#include "gauss.h"

// Wybór pivota
void choose_pivot(double **A, double *b, int n, int k) {
    int max = k;
    double eps = 1e-9;

    for (int i = k + 1; i < n; i++) {
        if (fabs(A[i][k]) > fabs(A[max][k]) + eps) {
            max = i;
        }
    }

    if (fabs(A[max][k]) < eps) {
        printf("Uwaga: pivot bliski zeru\n");
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

// Podstawienie wsteczne
void back_substitution(double **A, double *b, double *x, int n) {
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}
