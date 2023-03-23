#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

double *my_alloc(int i_min, int i_max);
void my_free(double **my_tab, int i_min);

int main() {
    double *arr = my_alloc(-5, 2);  //tablica o indeksach od -2 do 4
    printf("%f\n", arr[-5]);
    printf("%f\n", arr[2]);
    my_free(&arr, -5);
    my_free(&arr, -5);


    double *arr2 = my_alloc(-2, 4);
    int size = 7;
    for(int i = -2; i < 5; i++){
        *(arr2 + i) = 8.8;
        printf("%f, ", *(arr2+i));
    }
    my_free(&arr2, -2);
    my_free(&arr2, -2);

    return 0;
}

double *my_alloc(int i_min, int i_max){

    int ilosc_elementow = (i_max - i_min +1);
    double  *a; 
    a = (double*)malloc(ilosc_elementow * sizeof(double));

    for(int i = 0; i < abs(i_min); i++){
        a++;
    }
    return a;
}

void my_free(double **my_tab, int i_min){
    if (*my_tab == NULL){
        return;
    }
    for(int i = 0; i < abs(i_min); i++){
        (*my_tab)--;
    }
    free(*my_tab);
    *my_tab = NULL;
    
}
