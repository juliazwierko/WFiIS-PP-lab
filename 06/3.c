#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h> 
#include <ctype.h>

/*
Zadanie:
Następnie przekonwertuj łańcuch na notację zgodną z konwencją camelCase, np. 
raz_dwa_trzy_cztery powinno być zamienione na razDwaTrzyCztery. W tym celu 
do programu z 2. zadania dopisz własną funkcję, która będzie wykonywać tę 
konwersję przy użyciu strtok.

Przykład działania programu z zadań 2-3 (wypisywania pochodzą tylko z main):
./a.out ala ma 3 koty i psa
snake_case: ala_ma_3_koty_i_psa
camelCase:  alaMa3KotyIPsa
*/

char* camelCase(char* str) {
    char* res = malloc(strlen(str) + 1); // alokacja pamięci na nowy łańcuch
    *res = '\0';
    char* word = strtok(str, "_"); // podział wejściowego łańcucha na słowa
    int pos = 0; // aktualna pozycja w łańcuchu wynikowym
    
    while (word != NULL) {
        // przepisanie słowa do łańcucha wynikowego z zamianą pierwszej litery na wielką
        res[pos++] = toupper(*(word+0));
        res[pos] = '\0';
        strcat(res, word +1);
        
        pos += strlen(word) - 1;
        word = strtok(NULL, "_");
    }
    res[pos] = '\0'; // dodanie znaku końca łańcucha
    return res;
}

char *join_snake_case(char **a, int size, int length){
    char *res = malloc(sizeof(char) * length);
    strcpy(res, "");

    int i;
    for(i = 0; i < size-1; i++){
        strcat(res, *(a+i));
        strcat(res,"_");
    }
    strcat(res, *(i+a));

    return res;
}

int main(int argc, char *argv[]){
////////////////////ZADANIE 2://////////////////////////
    //1
    printf("Zadanie 2:\n");
    if(argc<2){
        printf("Wpisz argumenty.\n");
        return 0;
    }
    int length = 1;
    //2
    char **p = malloc(argc*sizeof(char*));
    for(int i=0; i<argc-1; i++) {
        int a = strlen(*(argv+i+1)) + 1;
        length += a + 1;
        *(p+i) = malloc(a * sizeof(char));
        strcpy(*(p+i),*(argv+i+1));
        printf("%s ", *(p+i));
    }
    int size = argc - 1;
    //3
        puts("");
        char *b = join_snake_case(p, size, length);
        puts(b);
        // free(b);
        // b = NULL;
    //4
    for(int i=0; i<argc-1; i++) {
        free(*(p+i));
        *(p+i) = NULL;
    }
    free(p);
    p = NULL;
////////////////////////////////////////////////////////

    // Zadanie 3:
    printf("\nZadanie 3:\n");
    char *m = camelCase(b);
    puts(m);
    // zwolnienia pamieci;
    free(b);
    b = NULL;
    free(m);
    m = NULL;

    return 0;
}
/*
    OUTPUT
    Zadanie 2:
    julcia pupcia krambambulka 
    julcia_pupcia_krambambulka

    Zadanie 3:
    JulciaPupciaKrambambulka
*/
