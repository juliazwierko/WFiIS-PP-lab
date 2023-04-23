/*
 Napisz funkcje zgodne z prototypami:
(30 pkt.) char *read_line(void);
która pobierze od użytkownika cały łańcuch aż do pierwszego znaku nowej linii i zwróci wskaźnik do tego łańcucha. 
Wskazówka: tablica przechowująca łańcuch musi być zaalokowana dynamicznie, a w razie potrzeby rozszerzana. Wczytujemy pojedyncze znaki, żeby móc znaleźć znak nowej linii '\n'.
(7.5 pkt.) char *trim(char *string);
Funkcja realokuje dynamicznie pamięć dla tablicy wskazywanej przez wejściowy parametr – tak, aby zwolnić pamięć po końcowych elementach tablicy, znajdujących się za znakiem końca łańcucha. 
(7.5 pkt.) void safe_free(void **my_tab);
Funkcja bezpiecznie zwalnia pamięć po jednowymiarowej tablicy zaalokowanej dynamicznie. Bezpiecznie == bez "wiszących wskaźników" (patrz końcówka wykładu nr 3) oraz nie próbuje zwalniać pamięci dla pustego wskaźnika – analogicznie do podobnej funkcji z zeszłego tygodnia.
Następnie przetestuj te funkcje w programie, żeby się przekonać o poprawności obsługi pamięci i wczytywania (korzystamy z valgrinda).

*/

#include <stdio.h>
#include <stdlib.h>

char *read_line();
char *trim(char *string);
void safefree(void **pp);

int main(){
    char *p=read_line();
    puts(p);
    safefree((void**)&p);
    safefree((void**)&p);//2 raz wywolanie
    return 0;
}

char *read_line(){ 

    char *arr = malloc(1*sizeof(char));
    int licznik = 0;
    char c;
    while(1) { 
        c=getchar();
        if(c=='\n')
        {
            break;
        }
        
        licznik++;
        arr = realloc(arr, (licznik+1) * sizeof(char));
        *(arr+licznik-1) = c;
    }
    *(arr+licznik)='\0';
    return arr; 
}

char *trim(char *arr){
    int licz = 0;
    char *ptr = arr;
    while(*ptr != '\0'){
        ptr++;
        licz++;
    }
    arr = realloc(arr, (licz+1) * sizeof(char));
    return arr;
}

void safefree(void**pp){
    if(*pp != NULL){
        free(*pp);
    }
    *pp = NULL;
}
