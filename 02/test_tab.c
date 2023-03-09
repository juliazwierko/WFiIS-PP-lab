/*
    #2
    Napisz funkcje, ktora przetestuje kod z 3 zadania. W tym celu 
    nalezy 300 razy wywolac tamta funkcje przy uzyciu losowych danych 
    (argumentach), po kazdym wywyolaniu sprawdajac, czy wyniki sa posortowane 
    prawidlowo. Jesli ktorys z testow sie nie powiedzie, nalezy zakonczyc program
    i poinformowac 
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#define SIZE 4

int i_rand(int min, int max) {
    return rand() % (max - min + 1) + min; 
} 

void swap(int* a, int* b);
void bubble_sort(int arr[], int n);
void losowanie(int* a, int* b, int* c, int* d);

int main(int argc, char const *argv[]){
    srand(time(NULL));
    int a, b, c, d;
    for(int i=0; i<300; i++){
        losowanie(&a,&b,&c,&d);

        int tab[] = {a, b, c, d}; 
        printf("Liczby przed sortowaniem\n");
        for(int i=0; i<SIZE; i++){
            printf("%d ", tab[i]);
        }
        printf("\n");

        printf("Liczby po sortowaniu\n");
        bubble_sort(tab, SIZE);
        for(int i=0; i<SIZE; i++){
            printf("%d ", tab[i]);
        }
        printf("\n\n");
    }

    return 0;
}

void bubble_sort(int arr[], int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<(n-i-1); j++){
            if(arr[j]>arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void losowanie(int* a, int* b, int* c, int* d){
    *a = i_rand(1,10);
    *b = i_rand(1,10);
    *c = i_rand(1,10);
    *d = i_rand(1,10);
    int tablica[4]={*a, *b, *c, *d};
    bubble_sort(tablica, SIZE);
}

/*
  OUTPUT jest takiego rodzaju:
  Liczby przed sortowaniem
  1 6 6 10 
  Liczby po sortowaniu
  1 6 6 10 

  Liczby przed sortowaniem
  8 5 4 9 
  Liczby po sortowaniu
  4 5 8 9 

  Liczby przed sortowaniem
  6 3 7 6 
  Liczby po sortowaniu
  3 6 6 7 
*/
