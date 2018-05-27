#include <cmath>

double waga(double x) {
    return 1 / sqrt(1 - x * x);
}

double wielomian(double x, double xWaga) {
    return waga(xWaga) * (x * x * x + 3 * x + 3);
}

double modul(double x, double xWaga) {
    return waga(xWaga) * (fabs(x) - 2);
}

double trygonometryczna(double x, double xWaga) {
    return waga(xWaga) * (cos(x));
}

double wykladnicza(double x, double xWaga) {
    return waga(xWaga) * (pow(3, x) - 4);
}