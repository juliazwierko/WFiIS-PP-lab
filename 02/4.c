/*
W katalogu lab_02 napisz funkcję, która przetestuje kod z 3. zadania.
W tym celu należy 100 razy wywołać tamtą funkcję przy losowych danych, 
po każdym wywołaniu sprawdzając, czy wyniki są posortowane prawidłowo. 
Należy również sprawdzić, czy zgadzają się z wartościami wejściowymi (tj.
czy nadal są to dokładnie te same trzy wartości,tylko zamienione kolejnością).
Jeśli któryś z testów się nie powiedzie, należy zakończyć program i poinformować
o błędzie.
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
    for(int i=0; i<100; i++){
        a = d_rand(0,10);
        b = d_rand(0,10);
        c = d_rand(0,10);
        double tab[] = {a, b, c};
        bubble_sort(tab, SIZE);
        printf("Liczby po sortowaniu\n");
        for(int i=0; i<SIZE; i++){
            printf("%f ", tab[i]);
        }
        a = tab[0];
        b = tab[1];
        c = tab[2];

        if(a>=b && b >=c){
            printf("good");
        }
        else{
            printf("zle");
            return 0;
        }
        printf("\n");  
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
