____Zadanie 1:____
a. (7.5 pkt.) W nowym pliku Student.c zapisać funkcję o prototypie: 
int cmp_student_by_last_name(const void *a, const void *b); 
która jest komparatorem dwóch studentów, porównującym ich tylko po nazwisku w kolejności alfabetycznej. Prototyp znajduje się już w pliku Student.h do dołączenia.
Będzie potrzebna też funkcja wypisująca dane studenta - można wykorzystać implementację zbliżoną do funkcji z wcześniejszych zajęć:
void print_student(const void *student) 
{ 
  assert(student != NULL); 
  const Student *student_a = student; 
  printf("Dane studenta: %s %s, wiek: %u, adres: %s\n", student_a->first_name, student_a->last_name, student_a->age, student_a->email); 
}
(5 pkt.) Napisać funkcję o prototypie:
char rand_letter(LETTER_CASE letter_case)
która zwraca losową literę. Dla jasności zapisu parametr wejściowy jest stałą typu wyliczeniowego:
typedef enum { LOWER, UPPER } LETTER_CASE; 
która definiuje, czy zwrócona litera ma być mała, czy duża.
Wskazówka: wygodnie będzie losować indeks tablicy "ABCDEFGHIJKLMNOPQRSTUVWXYZ" i zwracać element tablicy o tym indeksie (z uwzględnieniem wielkości liter - polecam funkcje tolower, toupper).
Na dole - pod punktem e - zamieszczono implementację funkcji i_rand, którą można wykorzystać w celu losowania liczby całkowitej.
(5 pkt.) Napisać funkcję o prototypie:
void rand_name(char *array, size_t max_len);
która wypełnia tablicę array o rozmiarze max_len losowym "imieniem" lub "nazwiskiem" (niech pierwsza litera będzie duża, a pozostałe małe; długości wylosowanych łańcuchów mogą być różne; losując litery, korzystamy z funkcji rand_letter).
(5 pkt.) Napisać funkcję o prototypie:
void rand_email(char *array, size_t max_len);
która wypełnia tablicę array o rozmiarze max_len losowym "adresem e-mail" studenta o schemacie: 
XXXX@student.agh.edu.pl 
(wylosować należy tylko litery przed znakiem '@', długość tej części łańcucha może być różna, ale całość nie może wychodzić poza tablicę).
(7.5 pkt.) Napisać funkcję o prototypie: 
Student *rand_student(void);
zwracającą wskaźnik do (zaalokowanego dynamicznie) nowego studenta o wylosowanych danych. Przy losowaniu wykorzystać zapisane wcześniej funkcje. 
Przypomnienie typowej implementacji funkcji losującej wartość całkowitą z zadanego przedziału:
int i_rand(int min, int max) 
{ 
  assert(min <= max); 
  return rand() % (max - min + 1) + min; 
}

____Zadanie 2:____
Główna część programu (do obsługi listy używamy funkcji dostarczonych w pliku list.c, korzystamy też z funkcji pomocniczych z 1. zadania):
(5 pkt.) W funkcji main obsłużyć dwa parametry wywołania programu: pierwszy to liczba całkowita n (konwersję łańcucha na liczbę całkowitą 
        zapewnia funkcja atoi), a drugi to nazwa pliku, do którego będziemy później zapisywać zawartość listy.
(10 pkt.) Utworzyć listę typu SortedList i wypełnić ją n losowymi studentami, wylosowanymi dzięki funkcji rand_student. Lista powinna
          być sortowana względem nazwiska w kolejności alfabetycznej (po to pisaliśmy funkcję cmp_student_by_last_name).
(2.5 pkt.) Wypisać zawartość listy (do tego też jest gotowa funkcja, należy do niej przekazać wskaźnik do funkcji wypisującej dane studenta).
(12.5 pkt.) Utworzyć plik binarny w trybie do zapisu o nazwie danej przez drugi z parametrów podanych przy wywołaniu programu. Wypisać do 
            tego pliku wszystkie struktury typu Student, do których wskaźniki przechowują węzły listy. 
            Uwaga: przy problemach z zapisaniem pętli przechodzącej węzeł po węźle, polecam zajrzeć np. do implementacji print_list w 
            pliku list.c.
(10 pkt.) Usunąć wszystkie elementy z listy, zwalniając przy tym całą pamięć zaalokowaną dynamicznie, i zamknąć plik.
          Wskazówki: dynamicznie zaalokowano każdy węzeł (wewnątrz funkcji add z pliku list.c). Za usunięcie i zwolnienie wszystkich węzłów 
          odpowiada 
          funkcja remove_all, jednak nie nadaje się do użycia w tym zadaniu. Dlaczego? Ponieważ nie zwalnia pamięci po strukturze Student, 
          którą również
          zaalokowaliśmy dynamicznie przy losowaniu (i nie może tego robić, ponieważ funkcja remove_all należy do implementacji listy, która 
          jest niezależna od struktury Student czy też innych danych, które chcielibyśmy przechowywać na liście). Co zatem zrobić? Proponuję 
          wybrać jedno z dwóch podejść:
          Prostsza wersja: do swojego programu skopiować funkcję remove_all pod inną nazwą i dodać w odpowiednim miejscu jej implementacji 
          zwalnianie pamięci po zaalokowanych przez nas danych.
          Wersja dla chętnych: w prostszej wersji mieszamy implementację listy z implementacją aplikacji klienckiej, która powinna z listy 
          tylko korzystać. Żeby się przed tym uchronić, można zmodyfikować funkcję remove_all w pliku list.c tak, żeby działała ogólnie. 
          Niech przyjmuje wskaźnik do funkcji odpowiadającej za zwolnienie jednego węzła i w odpowiednim miejscu wywołuje tę funkcję. Wówczas 
          możemy wywołać remove_all, przekazując prostą funkcję zwalniającą. 
          A w przypadku bez konieczności zwalniania pamięci po danych w węźle można by przekazać do tak zmienionej remove_all wskaźnik do 
          funkcji, która nic nie robi. Z kolei gdyby wewnątrz struktury Student były jeszcze dalsze wskaźniki do zaalokowanej dynamicznie
          pamięci, to również mielibyśmy możliwość przekazać do remove_all odpowiednio napisaną funkcję zwalniającą, ogólność rozwiązania 
          jest zachowana.
          
____Zadanie 3:____
Odczyt pliku binarnego 
(2.5 pkt.) W nowym otworzyć plik binarny, zapisany w poprzednim zadaniu, w trybie do odczytu. 
(17.5 pkt.) Do tablicy struktur Student wczytać dane z pliku, przy czym zakładamy, że program nie wie, ile struktur Student znajduje się w pliku (będzie potrzebna dynamiczna alokacja i realokacja). Zakończenie pętli wczytywania trzeba więc uzależnić od wartości zwracanej przez fread - co ta funkcja zwraca?
(5 pkt.) Wypisać dane studentów z tablicy.
(5 pkt.) Zwolnić pamięć zaalokowaną dynamicznie i zamknąć plik.
