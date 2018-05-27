#include <iostream>
#include <climits>
#include "funkcje.h"
#include "metody.h"
#include "zapisDoFunkcji.h"

using namespace std;

int main() {
    cout << "1 - 3x^3 + 3x^2 - 7x + 1" << endl;
    cout << "2 - sin(x)" << endl;
    cout << "3 - (3.4)^x -1" << endl;
    cout << "4 - cos(2x^3 + 4x^2 - 1)" << endl;
    cout << "wybierz dla jakiej funkcji chcesz WYZNACZYC miejsce zerowe: ";

    int opcja;
    cin >> opcja;

    double poczatekPrzedzialu;
    double koniecPrzedzialu;
    cout << "Podaj POCZATEK przedzialy: ";
    cin >> poczatekPrzedzialu;
    cout << "Podaj KONIEC przedzialu: ";
    cin >> koniecPrzedzialu;

    int wybor;
    double eps;
    int iloscIteracji;
    cout << "1 - Wprowadz EPS" << endl;
    cout << "2 - Wprowadz ilosc iteracji" << endl;
    cin >> wybor;
    if (wybor == 1) {
        cin >> eps;
        iloscIteracji = INT_MAX;
    } else if (wybor == 2) {
        cin >> iloscIteracji;
        eps = -1;
    } else {
        cout << "zly numer!";
        return -1;
    }

    funkcja wskF;
    funkcja wskP1F;

    switch (opcja) {
        case 1:
            wskF = wielomian;
            wskP1F = wielomianPochodna;
            break;
        case 2:
            wskF = sinus;
            wskP1F = sinusPochodna;
            break;
        case 3:
            wskF = wykladnicza;
            wskP1F = wykladniczaPochodna;
            break;
        case 4:
            wskF = zlozenie;
            wskP1F = zlozeniePochodna;
            break;
        default:
            cout << "zly numer!";
            return -1;
    }
    int iloscIteracjiBisekcja = 0;
    int iloscIteracjiNewtona = 1;

    double dokladnoscBisekcja;
    double dokladnoscNewton;

    double miejsceZeroweBisekcja;
    double miejsceZeroweNewtona;

    miejsceZeroweBisekcja = metodaBisekcji(poczatekPrzedzialu, koniecPrzedzialu, eps, wskF, iloscIteracjiBisekcja,
                                           iloscIteracji, dokladnoscBisekcja);
    miejsceZeroweNewtona = metodaNewtona(poczatekPrzedzialu, koniecPrzedzialu, eps, wskF, wskP1F, iloscIteracjiNewtona,
                                         iloscIteracji, dokladnoscNewton);

    punktyDoNarysowaniaWykresu(poczatekPrzedzialu, koniecPrzedzialu, wskF);
    miejscaZeroweDoPliku(wskF, miejsceZeroweBisekcja, miejsceZeroweNewtona);

    cout << "Ilosc iteracji dla metody bisekcji: " << iloscIteracjiBisekcja << endl;
    cout << "Miejsce zerowe wyznaczone dzieki metodzie bisekcji: " << miejsceZeroweBisekcja << endl;
    cout << "Dokladnosc dla metody bisekcji: " << dokladnoscBisekcja << endl;

    cout << "Ilosc iteracji dla metody Newtona: " << iloscIteracjiNewtona << endl;
    cout << "Miejsce zerowe wyznaczone dzieki metodzie Newtona: " << miejsceZeroweNewtona << endl;
    cout << "Dokladnosc dla metody Newtona: " << dokladnoscNewton << endl;
    return 0;
}
