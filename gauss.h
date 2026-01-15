#ifndef GAUSS_H
#define GAUSS_H

void choose_pivot(double **A, double *b, int n, int k);
void gaussian_elimination(double **A, double *b, int n);
void back_substitution(double **A, double *b, double *x, int n);

#endif
