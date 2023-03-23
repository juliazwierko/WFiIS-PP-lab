#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double *my_alloc(int i_min, int i_max);
void my_free(double **my_tab, int i_min);

int main() {
    double arr[] = {0.};
    // tablica o indeksach od -2 do 4


    printf("\n");
    return 0;
}

double *my_alloc(int i_min, int i_max){
    //////////////////////////////////////////////////////////
    int ilosc_elementow = (i_max - i_min);
    int *a; 
    a = (int*)malloc(ilosc_elementow * sizeof(double));

    
    for (int i = 0; i < ilosc_elementow; i++)
    {
        a[i] = 8.8;
        printf("arr[%d] = %lf, adres = %p\n", i, a[i], &a[i]);
    }
    printf("\n\n");
    //////////////////////////////////////////////////////////
    
    for (int i = 1; i < ilosc_elementow - 1; i++){
        //!!!
        a[i] = d_array_set_random(,);
        printf("arr[%d] = %lf, adres = %p\n", i, a[i], &a[i]);
    }
    free(a);
    return 0;
}

void my_free(double **my_tab, int i_min){
    
}
