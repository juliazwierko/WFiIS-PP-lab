/* 
W pliku functions_0d.c należy zapisać definicje czterech funkcji, 
które powinny działać zgodnie z komentarzem dokumentacyjnym w pliku 
nagłówkowym (reszta wyjaśnień: przy tablicy). 
Plik nagłówkowy dołączamy do tego kodu źródłowego poprzez:
#include "functions_0d.h".
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include "functions_0d.h"

//  #1
int i_rand(int min, int max);
double d_rand(double min, double max);
void i_swap(int *restrict first, int *restrict second);
void swap(void * first, void * second, size_t size);

//  #3
int i_rand(int min, int max) {
    return rand() % (max - min + 1) + min; 
} 

double d_rand(double min, double max) {
    double r = (double)rand() / RAND_MAX;
    return r * (max - min) + min; 
} 

void i_swap(int *restrict first, int *restrict second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

void swap(void * first, void * second, size_t size){
    char temp;
    char *p_first = first;
    char *p_second = second;
    for(size_t i=0; i<size; i++){
        temp = p_first[i];
        p_first[i] = p_second[i];
        p_second[i] = temp;
    }
}
