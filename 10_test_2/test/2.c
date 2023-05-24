// Zdefiniowanie funkcji porównującej + wywołanie qsort przyjmujące wskaźnik do tej funkcji (u nas to była po prostu tablica int'ów). 
// Specyfikacja funkcji qsort (argumenty formalne i ich typy) była podana. 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp (const void* a_p, const void* b_p){
    int a = *((const int*)a_p);
    int b = *((const int*)b_p);

    return a - b;
}

int main(void) {
    int tab[] = {12, 36, 72, 8, [8] = 44, 30};
    size_t n = sizeof(tab)/sizeof(*tab); //wyliczamy ilosc elementow
    
    for(size_t i = 0; i < n; i++){
        printf("%d ", *(tab+i));
    }
    printf("\n\n");

    qsort(tab, n, sizeof(*tab), cmp);

    for(size_t i = 0; i < n; i++){
        printf("%d ", *(tab+i));
    }
    
    return 0;
}
