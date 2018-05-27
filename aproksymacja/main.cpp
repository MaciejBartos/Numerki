#include <iostream>
#include "iloscPunktowOrazWskazniki.h"
#include "funkcje.h"
#include "metodaSimpsonaOrazWielomianCzebyszewa.h"
#include "daneDoWykresu.h"
#include "wspolczynniki.h"

int main() {
    double a, b;

    std::cout << "Podaj przedzial: " << std::endl;
    std::cin >> a;
    std::cin >> b;

    int stopienWielomianu;
    std::cout << "Podaj stopien wielomianu: " << std::endl;
    std::cin >> stopienWielomianu;

    double dokladnosc;
    std::cout << "Podaj dokladnosc dla calkowania metoda Simpsona: " << std::endl;
    std::cin >> dokladnosc;


    std::cout << "1 - x^4 - 2x^2 - 3" << std::endl;
    std::cout << "2 - |x|" << std::endl;
    std::cout << "3 - cos(x)" << std::endl;
    std::cout << "4 - 3^x" << std::endl;
    std::cout << "Wybierz funkcje: " << std::endl;

    int opcja;
    std::cin >> opcja;

    wskaznik wskFunckja1;
    wskaznik wskFunckja2 = wielomianCzebyszewa;

    switch (opcja) {
        case 1:
            wskFunckja1 = wielomian;
            break;
        case 2:
            wskFunckja1 = modul;
            break;
        case 3:
            wskFunckja1 = trygonometryczna;
            break;
        case 4:
            wskFunckja1 = wykladnicza;
            break;
        default:
            std::cout << "zly numer" << std::endl;
            return -1;
    }

    double *tabX = new double[iloscPunktow];
    double *tabY = new double[iloscPunktow];

    std::vector<double> wspolczynniki = wspolczynnikiAproksymacja(a, b, dokladnosc, stopienWielomianu, wskFunckja1,
                                                                  wskFunckja2);
    for (int i = 0; i < wspolczynniki.size(); ++i) {
        std::cout << "a" << i << "=" << wspolczynniki[i] << std::endl;
    }
    daneDoWykresuAproksymowana(tabX, tabY, a, (b - a) / (double) iloscPunktow, wskFunckja1, stopienWielomianu);
    zapisDoPlikuAproksymowana(tabX, tabY);

    daneDoWykresuAproksymacja(tabX, tabY, a, (b - a) / (double) iloscPunktow, wspolczynniki);
    zapisDoPlikuAproksymacja(tabX, tabY);

    delete[]tabX;
    delete[]tabY;

    return 0;
}
