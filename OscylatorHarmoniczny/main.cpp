#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib>

using namespace std;

double w0, B, A, Omega, q, xt, xy, vy, t_max = 7, h = 0.001;

double fun_1(double y1) {
    return y1;
}

double fun_2(double x, double y1, double y2) {
    return (A * sin(Omega * x + q)) - w0 * w0 * y1 - 2 * B * y2;

}

double rungego_dokladna(double tab1[], double tab2[], int i) {

    double t1 = xt;
    double y1 = xy;
    double y2 = vy;


    double K11 = h * fun_1(y2);
    double K21 = h * fun_2(t1, y1, y2);

    double K12 = h * fun_1(y2 + (0.4 * K21));
    double K22 = h * fun_2(t1 + (0.4 * h), y1 + (0.4 * K11), y2 + (0.4 * K21));

    double K13 = h * fun_1(y2 + (0.29697760 * K21) + (0.15875966 * K22));
    double K23 = h * fun_2(t1 + (0.45573726 * h), y1 + (0.29697760 * K11) + (0.15875966 * K12),
                           y2 + (0.29697760 * K21) + (0.15875966 * K22));

    double K14 = h * fun_1(y2 + (0.21810038 * K21) - (3.05096470 * K22) + (3.83286432 * K23));
    double K24 = h * fun_2(t1 + h, y1 + (0.21810038 * K11) - (3.05096470 * K12) + (3.83286432 * K13),
                           y2 + (0.21810038 * K21) - (3.05096470 * K22) + (3.83286432 * K23));

    tab1[i] = y1 + 0.17476028 * K11 - 0.55148053 * K12 + 1.20553547 * K13 + 0.17118478 * K14;
    tab2[i] = y2 + 0.17476028 * K21 - 0.55148053 * K22 + 1.20553547 * K23 + 0.17118478 * K24;

}


double runge(double tab1[], double tab2[], int i) {

    double t1 = xt;
    double y1 = xy;
    double y2 = vy;


    double K11 = h * fun_1(y2);
    double K21 = h * fun_2(t1, y1, y2);

    double K12 = h * fun_1(y2 + (0.5 * K21));
    double K22 = h * fun_2(t1 + (0.5 * h), y1 + (0.5 * K11), y2 + (0.5 * K21));

    double K13 = h * fun_1(y2 + (0.5 * K22));
    double K23 = h * fun_2(t1 + (0.5 * h), y1 + (0.5 * K12), y2 + (0.5 * K22));

    double K14 = h * fun_1(y2 + K23);
    double K24 = h * fun_2(t1 + h, y1 + K13, y2 + K23);

    tab1[i] = y1 + ((K11 + 2 * K12 + 2 * K13 + K14) / 6.0);

    tab2[i] = y2 + ((K21 + 2 * K22 + 2 * K23 + K24) / 6.0);

}


void zapis_do_pliku_1(double tab3[], double tab1[], int t) {
    fstream plik;
    plik.open("plik1.txt", ios::out | ios::trunc);
    if (plik.good() == true) {
        for (int i = 0; i < t; i++) {
            plik << tab3[i] << " " << tab1[i] << endl;
        }

        plik.close();
    }
}

void zapis_do_pliku_2(double tab3[], double tab2[], int t) {
    fstream plik;
    plik.open("plik2.txt", ios::out | ios::trunc);
    if (plik.good() == true) {
        for (int i = 0; i < t; i++) {
            plik << tab3[i] << " " << tab2[i] << endl;
        }

        plik.close();
    }
}

void zapis_do_pliku_1_1(double tab3[], double tab2[], int t) {
    fstream plik;
    plik.open("plik2_1.txt", ios::out | ios::trunc);
    if (plik.good() == true) {
        for (int i = 0; i < t; i++) {
            plik << tab3[i] << " " << tab2[i] << endl;
        }

        plik.close();
    }
}

void zapis_do_pliku_2_2(double tab3[], double tab2[], int t) {
    fstream plik;
    plik.open("plik2_2.txt", ios::out | ios::trunc);
    if (plik.good() == true) {
        for (int i = 0; i < t; i++) {
            plik << tab3[i] << " " << tab2[i] << endl;
        }

        plik.close();
    }
}

void wylicz_1(double tab1[], double tab2[], double tab3[]) {

    int i = 1;

    while (xt <= t_max) {
        runge(tab1, tab2, i);
        xt = xt + h;
        tab3[i] = xt;
        xy = tab1[i];
        vy = tab2[i];
        i++;
    }
}


void wylicz_2(double tab1[], double tab2[], double tab3[]) {

    int i = 1;

    while (xt <= t_max) {
        rungego_dokladna(tab1, tab2, i);
        xt = xt + h;
        tab3[i] = xt;
        xy = tab1[i];
        vy = tab2[i];
        i++;
    }
}

bool funa_case(int wybor) {

    switch (wybor) {
        case 1:
            w0 = 20 * M_PI, B = 0, A = 0, xt = 0, xy = 1, vy = 0;
            break;
        case 2:
            w0 = 20 * M_PI, B = 0.5, A = 0, xt = 0, xy = 1, vy = 0;
            break;
        case 3:
            w0 = 20 * M_PI, B = 10, A = 0, xt = 0, xy = 1, vy = 0;
            break;
        case 4:
            w0 = 20 * M_PI, B = 0.5, A = 50, Omega = 2 * M_PI;
            q = 0, xt = 0, xy = 0, vy = 0;
            break;
        case 5:
            w0 = 20 * M_PI, B = 0.5, A = 50, Omega = 20 * M_PI;
            q = 0, xt = 0, xy = 0, vy = 0;
            break;
        case 6:
            cout << "Podaj w0: ";
            cin >> w0;
            cout << "Podaj B: ";
            cin >> B;
            cout << "Podaj A: ";
            cin >> A;
            if (A != 0) {
                cout << "Podaj Omega: ";
                cin >> Omega;
                cout << "Podaj q: ";
                cin >> q;
            }
            cout << "Podaj t startowe: ";
            cin >> xt;
            cout << "Podaj vy gdzie v(t) = vy: ";
            cin >> vy;
            cout << "Podaj vy gdzie x(t) = xy: ";
            cin >> xy;
            cout << "Podaj t_max: ";
            cin >> t_max;
            cout << "Podaj h: ";
            cin >> h;
            break;
        default:
            cout << "Bledna opcja" << endl;
            break;
    }
}


int main() {

    int wybor;

    cout << "Wybierz wariant" << endl;
    cout << "1) w0 = 20M_PI, B = 0, A = 0, x(0) = 1, v(0) = 0 " << endl;
    cout << "2) w0 = 20M_PI, B = 0.5, A = 0, x(0) = 1, v(0) = 0" << endl;
    cout << "3) w0 = 20M_PI, B = 10, A = 0, x(0) = 1, v(0) = 0" << endl;
    cout << "4) w0 = 20M_PI, B = 0.5, A = 50, x(0) = 0, v(0) = 0, Omega = 2M_PI, q = 0 " << endl;
    cout << "5) w0 = 20M_PI, B = 0.5, A = 50, x(0) = 0, v(0) = 0, Omega = 20M_PI, q = 0 " << endl;
    cout << "6) wlasny wariant" << endl;
    cout << "Wybor: ";
    cin >> wybor;

    funa_case(wybor);

    int rozmiar = t_max / h;
    int pomocnicza1 = xy, pomocnicza2 = vy, pomocnicza3 = xt;

    double tab1[rozmiar];
    double tab2[rozmiar];
    double tab3[rozmiar];
    double tab1_1[rozmiar];
    double tab2_2[rozmiar];

    wylicz_1(tab1, tab2, tab3);

    xy = pomocnicza1;
    vy = pomocnicza2;
    xt = pomocnicza3;
    wylicz_2(tab1_1, tab2_2, tab3);


    tab1[0] = pomocnicza1; //dla tej zwyk�ej metody
    tab2[0] = pomocnicza2;
    tab1_1[0] = pomocnicza1; // dla najdok�adniejszej
    tab2_2[0] = pomocnicza2;
    tab3[0] = pomocnicza3;

    zapis_do_pliku_1(tab3, tab1, rozmiar);
    zapis_do_pliku_2(tab3, tab2, rozmiar);
    zapis_do_pliku_1_1(tab3, tab2_2, rozmiar);
    zapis_do_pliku_2_2(tab3, tab1_1, rozmiar);


    for (int i = 0; i < 10; i++) {
        cout << tab3[i] << " " << tab1[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << tab3[i] << " " << tab2[i] << endl;
    }


    return 0;
}
