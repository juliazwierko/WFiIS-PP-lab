#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void odwroc(int* arr, int n);

void zamiana(int *x, int *y);

void wymien_tablice(int* arr, int* arr2, int n);


int main()
{   
    int x = 1;
    int y = 2;
    printf("wartosc x do zamiany: %d\n", x);
    printf("wartosc y do zamiany: %d\n", y);

    zamiana(&x, &y);
    printf("wartosc x do zamiany: %d\n", x);
    printf("wartosc y do zamiany: %d\n", y);

    int arr[]={1,2,3,4,5,6,7,8,9,10};
    unsigned size = sizeof(arr)/sizeof(int);

    printf("Tablica przed odwracaniem\n");
    for(int i=0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\n");

    printf("Tablica po odwracaniu\n");
    odwroc(arr, size-1);
    for(int i=0; i<size; i++)
        printf("%d\t", arr[i]);

    printf("\nTablica arr2 przed zamiana:\n");
    int arr2[]={1,0,1,0,1,0,1,0,1,0};
    unsigned size2 = sizeof(arr2)/sizeof(int);

    for(int i=0; i<size2; i++)
        printf("%d\t", arr2[i]);

    wymien_tablice(arr, arr2, size);
    printf("\nTablicy 1 i 2 po zamianie:\n");
    for(int i=0; i<size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    for(int i=0; i<size2; i++)
        printf("%d\t", arr2[i]);
    printf("\n");

    return 0;
}

void zamiana(int *x, int *y){
    int swap = *x;
    *x = *y;
    *y = swap;
}

void odwroc(int* arr, int n){
    for(int i=0; i<n/2; i++)
        zamiana(arr+i, arr+n-i);
}

void wymien_tablice(int* arr, int* arr2, int n){
    for (int i=0; i<n; i++)
        zamiana(arr+i,arr2+i);
}
