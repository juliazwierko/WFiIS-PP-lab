//Qsort dla tablicy charów
#include <stdio.h>
#include <string.h>

int compare(const void *a_1, const void *b_1){
    char a = *(const char*)a_1;
    char b = *(const char*)b_1;

    if(a<b){
        return -1;
    }
    if(a>b){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void) {
    char array[] = "Julka_lubi_Pawelku_i_lody_czekoladowe_;3";
    int size = strlen(array);

    printf("Tablica przed sortowaniem:\n");
    puts(array);

    qsort(array, size, sizeof(*array), compare);
    printf("Tablica po sortowaniu:\n");
    puts(array);
    return 0;
}

//OutPut:
// Tablica przed sortowaniem:
// Julka_lubi_Pawelku_i_lody_czekoladowe_;3
// Tablica po sortowaniu:
// 3;JP______aaabcddeeeiikkklllllooouuuwwyz
