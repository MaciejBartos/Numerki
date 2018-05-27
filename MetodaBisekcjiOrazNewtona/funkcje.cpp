#include <cmath>
#include <iostream>
#include <vector>
#include "funkcje.h"


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

double wielomianPochodna(double x) {
    std::vector<double> parametry;
    parametry.push_back(9);
    parametry.push_back(6);
    parametry.push_back(-7);
    return schematHornera(parametry, x);
}

double sinus(double x) {
    return sin(x);
}

double sinusPochodna(double x) {
    return cos(x);
}

double wykladnicza(double x) {
    return pow(3.4, x) - 1;
}

double wykladniczaPochodna(double x) {
    return pow(3.4, x) * log(3.4);
}

double zlozenie(double x) {
    std::vector<double> parametry;
    parametry.push_back(2);
    parametry.push_back(4);
    parametry.push_back(0);
    parametry.push_back(-1);
    return cos(schematHornera(parametry, x));
}

double zlozeniePochodna(double x) {
    std::vector<double> parametry1, parametry2;
    parametry1.push_back(2);
    parametry1.push_back(4);
    parametry1.push_back(0);
    parametry1.push_back(-1);

    parametry2.push_back(-6);
    parametry2.push_back(-8);
    parametry2.push_back(0);
    return sin(schematHornera(parametry1, x)) * (schematHornera(parametry2, x));
}

