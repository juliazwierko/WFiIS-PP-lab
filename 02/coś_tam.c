#include <stdlib.h>
#include <stdio.h>
#define SIZE 4

void swap(int* a, int* b);
int* bubble_sort(int* a, int* b, int* c, int* d);

int main(int argc, char const *argv[])
{
    //  a = 10; b = 2; c = 5; d = 1;
    //  10, 2, 5, 1;
    //  1, 2, 5, 10;

    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    //  1 step
    int tab[] = {a, b, c, d}; // 10, 2, 5, 1 
    printf("Liczny przed sortowaniem");
    for(int i=0; i<(SIZE+1); i++){
        printf("%d", tab[i]);
    }

    swap(a,b);
    printf("a = %d, b = %d\n", a,b);

    //  2 step
    printf("Liczby po sortowaniu");
    int nowa_tab[SIZE];
    nowa_tab[0] = sortowanie(&a, &b, &c, &d);
    for(int i=0; i<(SIZE+1); i++){
        printf("%d", nowa_tab[i]);
    }

    return 0;
}

int* bubble_sort(int* a, int* b, int* c, int* d){
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
