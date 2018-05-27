#include <iostream>
#include "operacjeNaMacierzy.h"
#include "warunkiNaRodzajMacierzy.h"

int methodGauss(double **matrix, double *x, int n) {
    int mainDiagonalPossition = 0;
    double variable;
    for (int column = 0; column < n - 1; ++column) {
        if (matrix[mainDiagonalPossition][mainDiagonalPossition] == 0) {
            swapPosition(matrix, n, x, mainDiagonalPossition);
        }
        for (int row = column + 1; row < n; ++row) {
            variable = matrix[row][column] / matrix[mainDiagonalPossition][mainDiagonalPossition];
            for (int possition = 0; possition < n; ++possition) {
                matrix[row][possition] -= variable * matrix[mainDiagonalPossition][possition];
            }
            x[row] -= variable * x[mainDiagonalPossition];

        }
        mainDiagonalPossition++;
    }
    return checkIfNotAllNumbersInRowAreZeros(matrix, n, x);
}

