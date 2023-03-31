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
