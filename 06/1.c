#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h> 
#include <ctype.h>

/*
(30 pkt.) Poniższe zadanie należy wykonać z tablicą zadeklarowaną w main jako:
double **triangle;
Napisz program z tablicą dwuwymiarową o nieregularnym (trójkątnym) kształcie:
Zaalokuj tablicę dwuwymiarową, która będzie miała tyle wierszy, ile poda użytkownik w pierwszym parametrze wywołania programu: 
argv[1]. Każdy z wierszy ma mieć coraz więcej elementów, tzn. wiersz o indeksie 0 ma 1 element, wiersz o indeksie 1 ma 2 elementy, itd.
Wypełnij tę tablicę w dowolny sposób (np. przy pomocy swojej funkcji d_array_set_random).
Wypisz tablicę.
Zwolnij pamięć.
*/

int main(int argc, char *argv[]){
    //  Argumenty
    if(argc<2){
        printf("Wpisz argumenty.\n");
        return 0;
    }

    //  Deklaracja
    double **triangle = malloc(atoi(argv[1])*sizeof(double*));
    if(atoi(argv[1])>0){
        
        for(int i=0; i<atoi(argv[1]); i++){
            
            *(triangle+i) = malloc(((i+1)*sizeof(double)));
            
                for(int j = 0; j < i+1; j++){
                *(*(triangle + i)+j) = 1.0;
                printf("%f", *(*(triangle + i)+j));
                }
        
            printf("\n"); 
        }

    }
    //  Zwolnienie pamieci:
    for(int i=0; i<atoi(argv[1]); i++) {
        free(*(triangle+i));
        *(triangle+i) = NULL;
    }
    free(triangle);
    triangle = NULL;
    return 0;
}
