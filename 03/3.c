/*
   Do kodu biblioteki z dzisiejszych zajęć dopisz funkcje, które przyjmują 
   dokładnie dwa parametry: wskaźnik first i last do stałych elementów 
   tablicy typu double (rozumiane tak, jak w poprzednim zadaniu) oraz zwracają:
   a) sumę elementów tablicy,
   
   b) średnią arytmetyczną 𝜇
   
   c) odchylenie standardowe, liczone według wzoru: 
   sqrt(1/n * sigma(od i=0 do n -1)(xi - 𝜇)^2,
   gdzie xi to kolejny element tablicy o rozmiarze 𝑛
   (rozmiar należy wyznaczyć na podstawie wskaźników!),
   
   d)wskaźnik do najmniejszego elementu,
   
   e)wskaźnik do największego elementu.
*/

#include <stdlib.h>
#include "../my_functions/functions_0d.h"
#include "../my_functions/functions_1d.h"
#include <stdio.h>
#include <time.h>

#include <math.h>

//a
double suma(const double *  first, const double * last);
//b
double srednia(const double *  first, const double * last);
//c
double odchylenie_standartowe(const double *  first, const double * last);
//d
const double * wszanik_min(const double * first, const double * last);
//e
const double * wszanik_max(const double * first, const double * last);

int main() {
    return 0;
}

//a
double suma(const double * first, const double * last){
    double SUMA = 0.;
    while(first!=last){
        SUMA = SUMA + *(first);
        first++;
    }
    SUMA += *first;
    return SUMA;
}

//b
double srednia(const double * first, const double * last){
    int ROZMIAR = last - first; //dlugosc tablicy (odejmowanie wskaznikow)
    double SUMA = suma(first, last);
    double SREDNIA = SUMA/ROZMIAR;
    return SREDNIA;
}

//c
double odchylenie_standartowe(const double *  first, const double * last){
    int n = last - first; //dlugosc tablicy (odejmowanie wskaznikow)
    double b = 1.;
    double SUMA = 0.;
    //znaczek sigma
    for(int i = 0; i < (n-1); i++){
        double a = (*first - srednia(first, last));
        double b = pow(a,2);
        SUMA += b;
        first++;
    }

    b += (*last - srednia(first, last));
    b = pow(b,2);

    b *= (1./n);

    b = sqrt(b);

    return b;
}

//d
const double * wszanik_min(const double * first, const double * last){
    const double *ptr_1 = first;
    while(first!=last){
        if(*(first) < *(ptr_1))
            ptr_1 = first;
        first++;
    }
    if (*(ptr_1) > *last){
        ptr_1 = first;
    }
    return ptr_1;
}

//e
const double * wszanik_max(const double * first, const double * last){
    const double *ptr_1 = first;
    while(first!=last){
        if(*(first) > *(ptr_1))
            ptr_1 = first;
        first++;
    }
    if (*(ptr_1) < *last){
        ptr_1 = first;
    }
    return ptr_1;
}
