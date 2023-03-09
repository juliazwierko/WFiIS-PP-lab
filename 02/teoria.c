#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int tab[9][9];
    //  Wypisuwanie tablicy typu tab[][]
    int k,j; // k-wierszy, j-kolumny;
    for(k=0; k<9; k++){
        for(j=0; j<9; j++){
            tab[k][j] = 7;
            printf("%d", tab[k][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
    Wynik: Macierz 9x9
    777777777
    777777777
    777777777
    777777777
    777777777
    777777777
    777777777
    777777777
    777777777
*/
