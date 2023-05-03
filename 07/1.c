/*
  Zaimplementuj funkcję o prototypie:
  void my_printf(const char *format, ...);
  która wypisuje łańcuch podany przez użytkownika w sposób podobny do funkcji printf. 
  Nasza uproszczona wersja my_printf powinna obsługiwać cztery specyfikatory: %o, %X, %u oraz %s. 
  Samo wypisywanie poszczególnych fragmentów łańcucha (czyli w tym również wartości liczbowych) 
  wewnątrz my_printf może być zrealizowane dowolnie, nawet z wykorzystaniem funkcji printf.
  Funkcję należy wywołać w main. Przykłady, które powinny być obsługiwane:
  const char *text8 = "Liczba osemkowa";
  const char *text10 = "Liczba dziesietna";
  const char *text16 = "Liczba szesnastkowa";
  unsigned int decimal = 2662834401u;

  my_printf("");
  my_printf("Brak specyfikatorow\n");
  my_printf("%s", text10);
  my_printf("\t%u\n", decimal);
  my_printf("Jeden specyfikator: %X, koniec!\n", decimal);
  my_printf("%s: %u, %s: %o, %s: %X\n", text10, decimal, text8, decimal, text16, decimal);

  Wyświetlony przez program efekt powinien być identyczny, jak po użyciu funkcji printf z tymi samymi argumentami. 
  Można założyć, że znak '%' w formacie jest zarezerwowany tylko dla poprawnego użycia specyfikatorów.
*/
#include <stdarg.h>
#include <stdio.h>

void my_printf(const char *format, ...) {
    va_list arguments;
    va_start(arguments, format);

    while (*format != '\0') {
        if (*format == '%') { //szukamy znak-specyfikator;
            format++;
            switch (*format) {
                case 'o':   //%o
                    printf("%o", va_arg(arguments, unsigned int));
                    break;
                case 'X':   //%%X
                    printf("%X", va_arg(arguments, unsigned int));
                    break;
                case 'u':   //%u
                    printf("%u", va_arg(arguments, unsigned int));
                    break;
                case 's':   //%s
                    printf("%s", va_arg(arguments, char*));
                    break;
                default:
                    break;
            }
        } else {
            putchar(*format);
        }
        format++;
    }
    va_end(arguments);
}   

int main(){
    const char *text8 = "Liczba osemkowa";
    const char *text10 = "Liczba dziesietna";
    const char *text16 = "Liczba szesnastkowa";
    unsigned int decimal = 2662834401u;

    my_printf("");
    my_printf("Brak specyfikatorow\n");
    my_printf("%s", text10);
    my_printf("\t%u\n", decimal);
    my_printf("Jeden specyfikator: %X, koniec!\n", decimal);
    my_printf("%s: %u, %s: %o, %s: %X\n", text10, decimal, text8, decimal, text16, decimal);

    printf("\n");
    return 0;
}
