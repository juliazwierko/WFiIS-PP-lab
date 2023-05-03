/*
 Zaimplementuj funkcję o prototypie:
  int my_charcmp(char a, char b);
  która porównuje dwa znaki i zwraca:
  0, jeśli są równe;
  wartość ujemną, jeśli a zgodnie z zadaną niżej kolejnością powinno być wcześniej niż b;
  wartość dodatnią w przeciwnym wypadku.
  Zadana kolejność: pierwsze są cyfry, później litery niezależnie od wielkości, na końcu wszystkie pozostałe znaki.
  Kolejność cyfr jest naturalna (od '0' do '9'), kolejność liter: alfabetyczna, ale z pominięciem wielkości 
  ('a' oraz 'A' są przed 'b' oraz przed 'B', itd.), kolejność pozostałych znaków: jak w kodowaniu ASCII (tj. wystarczy odjąć a - b).
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
