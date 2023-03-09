#include <stdlib.h>
#include <stdio.h>
#define SIZE 4

void swap(int* a, int* b);
int* sortowanie(int* a, int* b, int* c, int* d);

int main(int argc, char const *argv[])
{
    /*
    a = 10,
    b = 2, 
    c = 5,
    d = 1;
    */

    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    int tab[] = {a, b, c, d};
    printf("Liczny przed sortoeaniem");
    for(int i=0; i<(SIZE+1); i++){
        printf("%d", tab[i]);
    }

    printf("Liczby po sortowaniu");
    int nowa_tab[SIZE];
    nowa_tab[SIZE] = sortowanie(&a, &b, &c, &d);

    return 0;
}

int* sortowanie(int* a, int* b, int* c, int* d){
    int tablica[SIZE] = {*a, *b, *c, *d};

    for(int i=0; i<SIZE-1; i++){
        for(int j=SIZE; j>i+1; j--){
            if(tablica[j-1]>tablica[j]){
                swap(tablica[j-1],tablica[j]);
            }
        }
    }
    return tablica;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
