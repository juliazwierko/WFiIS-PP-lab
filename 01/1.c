#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h> 

#define max_word_size 255

char show_menu();
char get_choice();
void clear_buffer(void);
void task_A(void);
void task_B(void);
void get_2ints(int *pa, int *pb);
void get_word(char *word);

int main(void)
{
    show_menu();
    char choice = 0;
    while ( (choice = get_choice())!= 'Q' ){
        switch(choice){
            
            case 'A':
                printf("Wybrana opcja - A\n");
                task_A(); // funkcja dla opcji 'A'
                break;
            
            case 'B':
                printf("Wybrana opcja - B\n");
                task_B();
                break;
            
            case 'C':
                printf("Wybrana opcja - C\n");
                break;

            case 'D':
                printf("Wybrana opcja - D\n");
                break;
            default:
                printf("Wpisana opcja jest zla");
                return 0; //konczymy program
        }
        show_menu();
    }
    
    printf("\n");
    return 0;
}

char show_menu(){
    printf("Wybierz opcje:\n");
    printf("-->      A: wykonaj mnozenie.\n");
    printf("-->      B: zadaj zagadke.\n");
    printf("-->      D: wyswietl dowcip.\n");
    printf("-->      Q: zakoncz program.\n");
    return 0;
}

char get_choice(void){
    char choice = 0;
    while( !isgraph(choice = getchar()) ) // '!' - zmieniamy falsz na prawde;
        continue; // inna opcja - ';', ale trudna do zauwazenia;
    clear_buffer();

    return toupper(choice); // toupper - rozwiazanie dla 'a' i 'A' 
}

void clear_buffer(void){
    while( getchar()!= '\n') 
        continue;
}

void task_A(void){
    printf("Podaj wartosci a i b\n");
    int a, b;
    get_2ints(&a,&b); //pobieranie 2 wartosciej
    int mnozenie = a*b;
    printf("wynik mnozenia a i b: %d\n", mnozenie);
}

void task_B(void){
    printf("Podaj stolice: ");
    char word[max_word_size + 1]; //255 - stala; +1 - znak konca lancucha;
    get_word(word);
    //string.h
    if((strcmp(word, "Warszawa")) == 0)
        printf("Zgadza sie\n");
    else 
        printf("Zle\n");
}

void get_word(char *word){
    while( scanf("%255s", word)!=1 ){ 
        clear_buffer(); // ???
    }
    clear_buffer();
}

/*
funkcja zamiany slowa na odpowiednie znaki:
change_word(word);
void change_word(char *word){
    word[0] = toupper(word[0]);
    for(int i = 0; word[0]!= '\0'; ++i){
        word[i] = tolower(word[i])
    }
}
*/

void get_2ints(int *pa, int *pb){  // !!! wskazniki w kontekscie tablic 2 wymiarowych. (na nast. zajeciach)
    while( (scanf("%d %d", pa, pb))!=2){  //scanf("%c",...); ("7%c");
        printf("Podaj jesccze raz: ");
        clear_buffer(); // !!!
    }
    clear_buffer(); // !!!
}

