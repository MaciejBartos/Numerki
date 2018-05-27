#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>


const double zeroValue = 0.0001;

double **create2dArray(int n) {
    double **array = new double *[n];
    for (int i = 0; i < n; ++i) {
        array[i] = new double[n];
    }
    return array;
}

void putNumbersFromFileToMatrix(double **matrix, int n, double *x) {
    std::ifstream file;
    file.open("matrix.txt");
    if (file.good()) {
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                file >> matrix[row][column];
            }
            file >> x[row];
        }
    }
    else{
        std::cout << "Problem z plikiem!";
    }
    file.close();
}

void putNumbersToMatrix(double **matrix, int n, double *x) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Wprowadz wartosci wspolczynnikow dla " << i + 1 << " linii:" << std::endl;
        for (int j = 0; j < n; ++j) {
            std::cout << j << "- ";
            std::cin >> matrix[i][j];
        }
        std::cout << "Oraz wartosc rowniania: ";
        std::cin >> x[i];
    }
}

void printMatrix(double **matrix, int n, double *x) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(10) << matrix[i][j] << " ";
        }
        std::cout << std::setw(10) << x[i];
        std::cout << std::endl;
    }
}

void swapPosition(double **matrix, int n, double *x, int currentPosition) {
    if (currentPosition < n - 1) {
        int step = 0;
        double swap;
        while (matrix[currentPosition+step][currentPosition] == 0 && currentPosition + step < n - 1) {
            step++;
        }
        for (int i = 0; i < n; ++i) {
            swap = matrix[currentPosition][i];
            matrix[currentPosition][i] = matrix[currentPosition + step][i];
            matrix[currentPosition + step][i] = swap;

        }
        swap = x[currentPosition];
        x[currentPosition] = x[currentPosition + step];
        x[currentPosition + step] = swap;
    }
}

void changeValueNearZeroToZeroInMatrix(double **matrix, int row, int column) {
    if (fabs(matrix[row][column]) < zeroValue) {
        matrix[row][column] = 0;
    }
}

void changeValueNearZeroToZeroInX(double *x, int row) {
    if (fabs(x[row]) < zeroValue) {
        x[row] = 0;
    }
}
