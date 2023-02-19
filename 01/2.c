#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void zamiana(int *x, int *y)
{
    int swap = *x;
    *x = *y;
    *y = swap;
}

int main()
{
    int x = 1;
    int y = 2;
    printf("wartosc x do zamiany: %d\n", x);
    printf("wartosc y do zamiany: %d\n", y);

    zamiana(&x, &y);
    printf("wartosc x do zamiany: %d\n", x);
    printf("wartosc y do zamiany: %d\n", y);

    return 0;
}
/*
    wartosc x do zamiany: 1
    wartosc y do zamiany: 2
    wartosc x do zamiany: 2
    wartosc y do zamiany: 1
*/
