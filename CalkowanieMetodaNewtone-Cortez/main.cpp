#include <iostream>
#include <cmath>
#include "funkcje.h"
#include "metodaGaussaOrazWzorSimpsona.h"
using namespace std;

int main() {
    double dokladnosc;
    int opcja;
    int wezlyGauss;

    cout << "wybierz funkcje: " << endl;
    cout << "1 - x^3 + 3x + 3 " << endl;
    cout << "2 - |x| - 2" << endl;
    cout << "3 - cos(x) - 1.5" << endl;
    cout << "4 - 3^x - 4" << endl;
    cin >> opcja;

    wskaznik wskFunkcja;

    switch (opcja) {
        case 1:
            wskFunkcja = wielomian;
            break;
        case 2:
            wskFunkcja = modul;
            break;
        case 3:
            wskFunkcja = trygonometryczna;
            break;
        case 4:
            wskFunkcja = wykladnicza;
            break;
        default:
            cout << "zly numer!!";
    }

    cout << "Podaj dokladnosc: " << endl;
    cin >> dokladnosc;
    cout << "Podaj ilosc wezlow: " << endl;
    cin >> wezlyGauss;

    cout << "Wartosc granicy wynosi: " << granica(dokladnosc, wskFunkcja) << endl;

    for (int i = 0; i < wezlyGauss; ++i) {
        cout << "Wartosc calki obliczana metoda Gaussa-Czebyszewa dla " << i+1 << " wezlow: " << metodaGaussa(i+1, wskFunkcja) << endl;
    }

    return 0;
}
