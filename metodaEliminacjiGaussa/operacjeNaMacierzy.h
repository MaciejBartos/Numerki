

#ifndef METODAELIMINACJIGAUSSA_OPERACJENAMACIERZY_H
#define METODAELIMINACJIGAUSSA_OPERACJENAMACIERZY_H

double **create2dArray(int n);
void putNumbersFromFileToMatrix(double **matrix, int n, double *x);
void putNumbersToMatrix(double **matrix, int n, double *x);
void printMatrix(double **matrix, int n, double *x);
void swapPosition(double **matrix, int n, double *x, int currentPosition);
void changeValueNearZeroToZeroInMatrix(double **matrix, int row, int column);
void changeValueNearZeroToZeroInX(double *x, int row);

#endif //METODAELIMINACJIGAUSSA_OPERACJENAMACIERZY_H
