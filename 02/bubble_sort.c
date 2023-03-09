/*
    Napisz funkcje, ktora przyjmuje 4 wskazniki do zmniennych całkowitych. 
    Funkcja, korzystając ze swap, powinna posortować ja rosnaco 
*/
#include <stdlib.h>
#include <stdio.h>
#define SIZE 4

void swap(int* a, int* b);
void bubble_sort(int arr[], int n);

int main(int argc, char const *argv[])
{
    //  a = 10; b = 2; c = 5; d = 1;
    //  przed:  10, 2, 5, 1;
    //  po:     1, 2, 5, 10;
    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    int tab[] = {a, b, c, d}; // 10, 2, 5, 1 
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
    printf("\n");

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

