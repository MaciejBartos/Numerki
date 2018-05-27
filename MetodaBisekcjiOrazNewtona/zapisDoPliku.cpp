#include <iostream>
#include <fstream>
#include "funkcje.h"
#include "zapisDoFunkcji.h"

void punktyDoNarysowaniaWykresu(double a, double b, funkcja fun) {
    double odleglosc = 0.1;
    std::ofstream plik;
    plik.open("punktyDoWykresu.txt");

    if (plik.good()) {
        for (double i = a; i <= b; i += odleglosc) {
            plik << i << " " << fun(i) << std::endl;
        }
        plik.close();
    } else {
        std::cout << "problem z plikiem!";
    }
}

void miejscaZeroweDoPliku(funkcja fun, double miejsceBisekcja, double miejsceNewtona) {

    std::ofstream plik;
    plik.open("miejscaZerowe.txt");

    if (plik.good()) {
        plik << miejsceBisekcja << " " << fun(miejsceBisekcja) << std::endl;
        plik << miejsceNewtona << " " << fun(miejsceNewtona);
        plik.close();
    } else {
        std::cout << "Problem z otworzeniem pliku!";
    }

}

