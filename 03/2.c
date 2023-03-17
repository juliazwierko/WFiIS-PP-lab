#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include "functions_1d.h"
#include "functions_0d.h" //dla losowania liczb

#define SIZE 10

//1
void i_array_print(const int *first, const int *last, const char *header);

//2
void d_array_print(const double *first, const double *last, const char *header);

//3
void i_array_set_zero(int *first, int *last);

//4
void d_array_set_zero(double *first, double *last);

//5
void i_array_set_random(int *first, int *last, int min, int max);

//6
void d_array_set_random(double *first, double *last, double min, double max);

////////////////////////////////////////////////////////////////////////////////

//1
void i_array_print(const int *first, const int *last, const char *header){
    printf("%s", header);
    while(first!=last){
        printf("%d", *first);
        first++;
    }
    printf("%d", last);
    return;
}

//2
void d_array_print(const double *first, const double *last, const char *header){
    printf("%s", header);
    while(first!=last){
        printf("%f", *first);
        first++;
    }
    printf("%f", last);
    return;
}

//3
void i_array_set_zero(int *first, int *last){
    while(first!=last){
        *first = 0;
        first++;
    }
    *last = 0.0;
    return;
}

//4
void d_array_set_zero(double *first, double *last){
    while(first!=last){
        *first = 0.0;
        first++;
    }
    *last = 0.0;
    return;
}

//5
void i_array_set_random(int *first, int *last, int min, int max){
    while(first!=last){
        *first = i_rand(min, max);
        first++;
    }
    *last = i_rand(min, max);
    return;
}

//6
void d_array_set_random(double *first, double *last, double min, double max){
    while(first!=last){
        *first = d_rand(min, max);
        first++;
    }
    *last = d_rand(min, max);
    return;
}
