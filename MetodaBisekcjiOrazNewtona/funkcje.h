#ifndef METODY_BISEKCJI_ORAZ_NEWTONA_FUNKCJE_H
#define METODY_BISEKCJI_ORAZ_NEWTONA_FUNKCJE_H

#include <vector>

typedef double (*funkcja)(double);

double wielomian(double x);

double wielomianPochodna(double x);

double sinus(double x);

double sinusPochodna(double x);

double wykladnicza(double x);

double wykladniczaPochodna(double x);

double zlozenie(double x);

double zlozeniePochodna(double x);

double schematHornera(std::vector<double> parametry, double x);


#endif //METODY_BISEKCJI_ORAZ_NEWTONA_FUNKCJE_H
