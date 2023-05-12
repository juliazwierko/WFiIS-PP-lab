/*
  Wersja z typedef.
  Do programu z punktu b) dopisz instrukcję z typedef, która zdefiniuje typ, będący wskaźnikiem do funkcji 
  przyjmującej jeden parametr typu double i zwracającej wartość typu double (jak nasze funkcje matematyczne 
  z programu). Popraw nagłówek funkcji print_value oraz deklarację tablicy skoku tak, żeby wykorzystać 
  zdefiniowany w ten sposób typ. Po tych zmianach program powinien wypisywać identyczne wyniki do wersji 
  z pliku zad_1.c.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double (*Function)(double);

double linear(double x);
double quadratic(double x);

#define X_MIN 0.0
#define X_MAX 5.0
#define DX 0.1
#define FUN_NR_MAX 8

void print_info(void);
void print_value(double x, Function fun);

// nowa funkcja;
double (* choose_fun(int fun_nr))(double);


int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        print_info();
        exit(-1);
    }

    //PIDPUNKT
    Function jump_table[9] = {exp, fabs, exp2, sqrt, sin, cos, ceil, linear, quadratic};


    for (double x = X_MIN; x < X_MAX + 0.1 * DX; x += DX) 
    {
        printf("%10g ", x); // Wypisywanie argumentu x
        for (int i = 1; i < argc; ++i)
        {
            int fun_nr = atoi(*(argv + i)); // Numer funkcji, wybranej przez użytkownika.
            print_value(x, jump_table[fun_nr]);
        }
        printf("\n");
    }
    return 0;
}

double linear(double x) { 
    return 2 * x + 1.5;
}
double quadratic(double x) { 
    return x * x - 2 * x + 1.5; 
}

//1 krok - zmiana naglowka 
void print_value(double x, Function fun)
{
    double y = fun(x);
    printf("%10g ", y);
}

void print_info(void)
{
    printf("Podaj numer(y) funkcji:\n");
    printf("0 - f(x) = e^x\n");
    printf("1 - f(x) = |x|\n");
    printf("2 - f(x) = 2^x\n");
    printf("3 - f(x) = sqrt(x)\n");
    printf("4 - f(x) = sin(x)\n");
    printf("5 - f(x) = cos(x)\n");
    printf("6 - f(x) = [x]]\n");
    printf("7 - f(x) =  2x + 1.5\n");
    printf("8 - f(x) = x^2 - 2x + 1.5\n");
}
