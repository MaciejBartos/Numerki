
#include <iostream>
#include <vector>
#include <cmath>

double schematHornera(std::vector<double> parametry, double x) {
    double wynik = parametry[0];
    for (int i = 1; i < parametry.size(); ++i) {
        wynik = wynik * x + parametry[i];
    }
    return wynik;
}

double wielomian(double x) {
    std::vector<double> parametry;
    parametry.push_back(3);
    parametry.push_back(3);
    parametry.push_back(-7);
    parametry.push_back(1);
    return schematHornera(parametry, x);
}

double zlozenie(double x) {
    return cos(fabs(x));
}

