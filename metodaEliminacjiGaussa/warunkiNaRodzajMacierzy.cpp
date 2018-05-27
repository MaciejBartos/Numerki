
#include "operacjeNaMacierzy.h"

int checkIfNotAllNumbersInRowAreZeros(double **matrix, int n, double *x) {
    int numberOfZeroInMatrix;
    int checkIfZeroInX;
    for (int row = 0; row < n; ++row) {
        numberOfZeroInMatrix = 0;
        checkIfZeroInX = 0;
        for (int column = 0; column < n; ++column) {
            changeValueNearZeroToZeroInMatrix(matrix, row, column);
            if (matrix[row][column] == 0) {
                numberOfZeroInMatrix++;
            }
        }
        changeValueNearZeroToZeroInX(x, row);
        if (x[row] == 0) {
            checkIfZeroInX++;
        }
        if (numberOfZeroInMatrix == n && checkIfZeroInX == 1) {
            return 0;
        } else if (numberOfZeroInMatrix == n  && checkIfZeroInX == 0) {
            return -1;
        }

    }
    return 1;
}