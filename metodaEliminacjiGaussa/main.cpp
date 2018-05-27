
#include <iostream>
#include "operacjeNaMacierzy.h"
#include "metodaGaussa.h"
#include "ukladRownan.h"

int main() {
    int n, option;
    std::cout << "Wprowadz ilosc rownan: ";
    std::cin >> n;

    std::cout << "1-wprowadz wspolczynniki do macierzy \n2-Pobierz wspolczynniki z pliku \n";
    std::cin >> option;

    double **matrix = create2dArray(n);
    double *x = new double[n];
    if (option == 1){
        putNumbersToMatrix(matrix, n, x);
    }
    else{
        putNumbersFromFileToMatrix(matrix, n, x);
    }
    printMatrix(matrix, n, x);
    std::cout << std::endl;
    int result = methodGauss(matrix, x, n);
    std::vector<double> solution = systemOfEquations(matrix, x, n);
    switch (result) {
        case 1:
            printMatrix(matrix, n, x);
            for (int i = 0; i < n; ++i) {
                std::cout << "x" << n - i << "=" << solution[i] << std::endl;
            }
            break;
        case 0:
            std::cout << "UKLAD NIEOZNACZONY!";
            break;
        case -1:
            std::cout << "UKLAD SPRZECZNY!";
            break;
    }

    return 0;
}