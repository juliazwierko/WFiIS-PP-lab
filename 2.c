#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 
#define N 10

int main()
{
    char tab[] = "JakiS Tekst Od julkI";
    for (int i=0; i<(sizeof(tab)/sizeof(char)); i++)
    {
        if (*(tab+i)< 91 && *(tab+i)>64)
        printf("%c", *(tab+i));
    }

    for (int i=0; i<(sizeof(tab)/sizeof(char)); i++)
    {
        if (*(tab+i)< 123 && *(tab+i)>96)
        printf("%c", *(tab+i));
    }

    return 0;
}
