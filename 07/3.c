/*
Uwaga: opisana niżej funkcja my_strcmp posłuży do sortowania przy pomocy funkcji qsort, a celem będzie posortowanie wskaźników do 
łańcuchów (od tego zależy sposób, w jaki obsługiwane będą parametry tej funkcji – jak w wykładzie nr 6, slajd 12).
Zaimplementuj funkcję o prototypie:
int my_strcmp(const void *a, const void *b);
która porównuje dwa łańcuchy, zwracając odpowiednio:
0, jeśli łańcuchy są identyczne,
wartość ujemną, jeśli pierwszy łańcuch powinien być wcześniej według zadanej niżej kolejności,
wartość dodatnią, gdy drugi łańcuch powinien być wcześniej.
Zadana kolejność łańcuchów: powinna być zgodna z rosnącą długością łańcuchów (krótsze łańcuchy na początku, dłuższe później). 
Jeśli porównywane łańcuchy mają tę samą długość, wówczas o ich kolejności decyduje porównywanie znak po znaku przy pomocy funkcji my_charcmp z poprzedniego zadania. 

Następnie wykorzystaj funkcję my_strcmp do posortowania wskaźników do łańcuchów:
const char *strings[] = {"Z", "u", "REh4HmPJRS", "One", "one", "[", "@$9325", "two", "THREE", "four", "415",
"@#$325", "@#$315", "@#9325", "five", "alpha", "zet", "0zero", "0123", "0", "(text)", "8", "@#$325"};
przy pomocy funkcji qsort (nie implementujemy sortowania samodzielnie!). Oczekiwany wynik po posortowaniu:

0
8
u
Z
[
415
One
one
two
zet
0123
five
four
0zero
alpha
THREE
(text)
@#9325
@#$315
@#$325
@#$325
@$9325
REh4HmPJRS
*/

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

int my_charcmp(char a, char b) {
    if (a == b) {
        return 0;
    } else if ((isdigit(a) && !isdigit(b)) || (isalnum(a) && !isalnum(b))) {
        return -1;
    } else if ((!isdigit(a) && isdigit(b)) || (!isalnum(a) && isalnum(b))) {
        return 1;
    } else  {
        if (isalpha(a) && isalpha(b)) {
            //pomijemy wielkosc literek:
            a = tolower(a);
            b = tolower(b);
        }
        if(a==b){
            return 0;
        }
        else if(a<b){
            return -1;
        }
        return 1;
    } 
}

int main(){
    //Testowanie dzialania funkcji:
    printf("--my_charcmp--\n");
    printf("('a','A')\n");
    int a = my_charcmp('Z','8');
    printf("->%d\n\n", a);

    printf("('1', '0')\n");
    int b = my_charcmp('1', '0');
    printf("->%d\n\n", b);

    printf("('A', '2')\n");
    int c = my_charcmp('A', '2');
    printf("->%d\n\n", b);

    printf("(',', '0')\n");
    int d = my_charcmp(',', '0');
    printf("->%d\n\n", b);

    return 0;
}
