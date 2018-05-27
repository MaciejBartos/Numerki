#ifndef CALKOWANIEMETODANEWTONE_CORTEZ_METODAGAUSSAORAZWZORSIMPSONA_H
#define CALKOWANIEMETODANEWTONE_CORTEZ_METODAGAUSSAORAZWZORSIMPSONA_H

typedef double(*wskaznik)(double, double);
double wzorSimpsona(double a, double b, double dokladnosc, wskaznik wskFunkcja);
double granica(double eps, wskaznik wskFunkcja);
double metodaGaussa(int n, wskaznik wskFunkcja);

#endif //CALKOWANIEMETODANEWTONE_CORTEZ_METODAGAUSSAORAZWZORSIMPSONA_H
