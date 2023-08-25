#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "functions_0d.h"

int i_rand(int min, int max){
    return rand() % (max - min + 1) + min; 
}

double d_rand(double min, double max){
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
