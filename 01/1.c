#include <stdio.h>
#include <stdlib.h>   //malloc
#include <string.h>
#include <ctype.h>
char* zamiana(char *tab, int n); 

int main(void)
{
    char tab[] = "Jakis Tekst od JullKII";
    int n = strlen(tab); //ilosc liter, 
    printf("Tablica przed edytowaniem:\n%s\n\n", tab);

    char *tab2 = zamiana(tab, n);
    printf("Tablica po edytowaniu:\n%s \n", tab2);
    free(tab2);
    tab2 = NULL;
    return 0;
}

char* zamiana(char *tab, int n){
    char *arr = malloc(n * sizeof(char));
    int j=0;
    
    if(arr)
    {
        for(int i=0; i<n; i++)
        {
            if (isupper(tab[i]))
                arr[j++] = tab[i];
        }

        for(int i=0; i<n; i++)
        {
            if (islower(tab[i]))
                arr[j++] = tab[i];
        }
    }
  
    return arr;
}
