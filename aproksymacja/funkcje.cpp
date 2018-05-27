#include <cmath>
#include "funkcje.h"

double wielomian(double x, int k){
    return x*x*x*x - 2*x*x -3;
}

double modul(double x, int k){
    return fabs(x);
}

double trygonometryczna(double x, int k){
    return cos(x);
}

double wykladnicza(double x, int k){
    return pow(3, x);
}