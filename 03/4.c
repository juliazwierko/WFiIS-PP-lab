/*
W katalogu lab_3 napisz funkcję, która dla przekazanej do niej tablicy elementów 
typu double wyznaczy sumę, średnią, odchylenie standardowe oraz wskaźniki 
do najmniejszego i największego elementu, korzystając przy tym z wcześniej 
napisanych funkcji, po czym przekaże je do funkcji wywołującej (np. do main). 
W main należy utworzyć tablicę, wypełnić ją losowymi wartościami z przedziału
[-5.0, 15.0], wypisać jej zawartość, po czym wywołać powyższą funkcję i wypisać 
uzyskane w ten sposób wartości.
*/

#include <stdlib.h>
#include "../my_functions/functions_0d.h"
#include "../my_functions/functions_1d.h"
#include <stdio.h>
#include <time.h>
#include <math.h>

#define SIZE 10

double wszystkie_parametry(double *tab, int n, double *sum, double *avg, double *odchylenie , double **min, double **max);

int main() {
    srand(time(NULL));
    double arr[SIZE] = {};
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = d_rand(-5.0, 15.0);
        printf("arr[%d] = %f\n", i, arr[i]);
    }
    printf("\n");
    double sum = 0.;
    double avg = 1.;
    double odchylenie = 1.;
    double *min;
    double *max;

    wszystkie_parametry(arr, SIZE, &sum, &avg, &odchylenie, &min, &max);
    //wywolanie funkchji
    pritnf("%f - suma\n", sum);
    pritnf("%f - suma\n", avg);
    pritnf("%f - suma\n", odchylenie);

    printf("%p - min\n", min);
    printf("%g -* min\n",*min);

    printf("%p - max\n", max);
    printf("%g -* max\n",*max);
    
    return 0;
}

double wszystkie_parametry(double *tab, int n, double *sum, double *avg, double *odchylenie , double **min, double **max){
    //a
    *sum = suma(tab, tab+(n-1));;
    //b
    *avg = srednia(tab, tab+(n-1));
    //c
    *odchylenie = odchylenie_standartowe(tab, tab+(n-1));
    //d
    *min =  wszanik_min(tab, tab+(n-1));
    //e
    *max = wszanik_max(tab, tab+(n-1));
}
