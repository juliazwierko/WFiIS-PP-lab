#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h> 
#include <ctype.h>

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
    //1
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
        free(b);
        b = NULL;

    //4
    for(int i=0; i<argc-1; i++) {
        free(*(p+i));
        *(p+i) = NULL;
    }
    free(p);
    p = NULL;
    return 0;
}
