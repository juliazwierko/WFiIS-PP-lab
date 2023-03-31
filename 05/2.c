#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *read_line();
char *find_first_char_from_set(const char *input_string, const char *set);
void safefree(void **pp);

int main(){
    printf("Input string:\n");
    char *input_string=read_line();
    //puts(input_string);
    
    printf("Set:\n");
    char *set=read_line();
    //puts(set);

    char *literka = find_first_char_from_set(input_string, set);
    printf("%s\n", literka);

    safefree((void**)&input_string);
    safefree((void**)&set);
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

char *find_first_char_from_set(const char *input_string, const char *set){
    const char *literka = NULL;
    
    const char *ptr = input_string; //szukamy znaki
    const char *pptr = set; //znaki

    int size_input = strlen(input_string);
    int size_set = strlen(set);

    for(int i = 0; i < size_input; i++){

        for (int j = 0; j < size_set; j++){

            if(*(pptr+j) == *(ptr+i)){
                literka = (ptr+i);
                return (char *)literka;
            }

        }
    }
    return NULL;
}

void safefree(void**pp){
    if(*pp != NULL){
        free(*pp);
    }
    *pp = NULL;
}
