/*
  W katalogu lab_02 napisz funkcję, która przyjmuje trzy adresy 
  zmiennych typu double. Funkcja, korzystając ze swap, powinna 
  posortować te wartości malejąco: przypisać największą wartość
  zmiennoprzecinkową pod pierwszy adres, środkową pod drugi, 
  a najmniejszą pod ostatni.
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "../my_functions/functions_0d.h"
#include <math.h>

#define SIZE 3

void bubble_sort(double arr[], int n);
void d_swap(double * a, double* b);

int main(int argc, char const *argv[])
{
    double a, b, c;
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    double tab[] = {a, b, c};
    printf("Liczby przed sortowaniem\n");
    for(int i=0; i<SIZE; i++){
        printf("%f ", tab[i]);
    }
    printf("\n");

    printf("Liczby po sortowaniu\n");
    bubble_sort(tab, SIZE);
    for(int i=0; i<SIZE; i++){
        printf("%f ", tab[i]);
    }
    printf("\n");

    return 0;
}

void bubble_sort(double arr[], int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<(n-i-1); j++){
            if(arr[j]<arr[j + 1]){
                d_swap(&arr[j], &(arr[j + 1]));
            }
        }
    }
}

void d_swap(double * a, double* b){
    double temp = *a;
    *a = *b;
    *b = temp;
}

