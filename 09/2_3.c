/*
  Zadania nr 2 i 3 będą dotyczyć funkcjonalności struktury, która przechowuje dane studenta.
  
  ->zadanie 2
  Zaimplementuj: 
  typ wyliczeniowy o nazwie student_status, w którym będą zdefiniowane trzy stałe o nazwach: STUDENT (o wartości 1), 
  GRADUATE (wartość 2), REMOVED (wartość -1).
  strukturę o nazwie Student, która będzie w stanie przechować 5 danych studenta: wskaźnik do łańcucha z imieniem, wskaźnik 
  do łańcucha z nazwiskiem, wiek, tablicę znakową z adresem oraz status (typ wyliczeniowy student_status).
  5 funkcji ustawiających wartości pól struktury: set_first_name, set_last_name, set_age, set_address oraz set_status 
  (np. set_first_name przypisuje wskaźnik do struktury oraz wskaźnik do łańcucha z imieniem, itd.). Przy ustawianiu adresu
  proszę uważać na niebezpieczeństwo wyjścia poza tablicę - najlepiej skorzystać z funkcji strncpy i upewnić się, 
  czy wklejony łańcuch jest zakończony prawidłowo.
  Funkcję initialize_student, która inicjalizuje/ustawia wszystkie pola struktury przy pomocy wywołań powyższych pięciu 
  funkcji na podstawie przekazanych do niej parametrów.
  Funkcję print_student, wypisującą zawartość struktury przekazanej przez wartość (nie wskaźnik!) w formie:
  Dane studenta: Artur Kowalczyk, wiek: 22, adres: ul. Miechowska, Krakow, status: usuniety z listy studentow.
  Funkcję copy_of, tworzącą kopię struktury: powinna zwracać wskaźnik do nowej struktury, która zostanie zainicjalizowana
  wartościami skopiowanymi z innej struktury, przekazanej jako jedyny parametr. Funkcję get_older, która zwraca starszego 
  spośród dwóch przekazanych do niej studentów (powinna zwracać przez wartość, a nie wskaźnik).
  
  ->zadanie 3
  Do programu z 2. zadania dopisz funkcję main, w której wykorzystasz wszystkie napisane wcześniej funkcje:
  Utwórz co najmniej 3 zmienne - studentów, z których jedna będzie inicjalizowana przy pomocy zwykłego inic
  jalizatora przy deklaracji, druga - przy pomocy funkcji initialize_student, trzecia - przy pomocy funkcji get_older.
  Wypisz dane powyższych studentów (funkcja print_student).
  Utwórz tablicę studentów, którą wypełnisz wcześniej utworzonymi studentami. Wypisz tablicę (funkcja print_student).
  Utwórz tablicę wskaźników do studentów, którą wypełnisz kopiami elementów poprzedniej tablicy (funkcja copy_of). 
  Wypisz struktury, na które wskazują te elementy (funkcja print_student).
  Zwolnij pamięć zaalokowaną dynamicznie.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definicja maxa
#define MAX 100

//typ wyliczyniowy
typedef enum {
    STUDENT = 1,
    GRADUATE = 2,
    REMOVED = -1
} student_status;

//struktura student
typedef struct {
    char* first_name;
    char* last_name;
    int age; 
    char adres[MAX]; //musimy sami zalozyc ilosc elementow 
    student_status status;
}Student;

////////////////////////////////////////////////////////////
void set_first_name(Student *st, char* first_name) {
    st ->first_name = first_name;
}
    
void set_last_name(Student *st, char* last_name){
    st ->last_name = last_name;
}

void set_age(Student *st, int n){
    st ->age = n;
}

void set_adres(Student* student, const char* adres) {
    strncpy(student->adres, adres, sizeof(student->adres) - 1);
    student->adres[sizeof(student->adres) - 1] = '\0';
}

void set_status(Student* student, student_status status) {
    student->status = status;
}

void initialize_student(Student* student, const char* first_name, const char* last_name, int age, const char* adres, student_status status) {
    set_first_name(student, first_name);
    set_last_name(student, last_name);
    set_age(student, age);
    set_adres(student, adres);
    set_status(student, status);
}

void print_student(Student student) {
    const char* status_str;
    switch (student.status) {
        case STUDENT:
            status_str = "student";
            break;
        case GRADUATE:
            status_str = "graduate";
            break;
        case REMOVED:
            status_str = "removed from student list";
            break;
        default:
            status_str = "unknown";
            break;
    }
    printf("Dane studenta: %s %s , wiek: %d, adres: %s, status: %s\n",
           student.first_name, student.last_name, student.age, student.adres, status_str);
}

Student* copy_of(const Student* student) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    if (new_student != NULL) {
        initialize_student(new_student, student->first_name, student->last_name, student->age, student->adres, student->status);
    }
    return new_student;
}

Student get_older(Student student1, Student student2) {
    if (student1.age > student2.age) {
        return student1;
    } else {
        return student2;
    }
}

int main(){
    Student student1;
    initialize_student(&student1, "Julia", "Zwierko", 18, "ul. Reymonta, Krakow", STUDENT);
    print_student(student1);

    Student student2;
    initialize_student(&student2, "Paweł", "Sipko", 23, "ul. Reymonta, Krakow", STUDENT);
    print_student(student2);

    Student* student3 = copy_of(&student1);
    print_student(*student3);
    free(student3);

    Student older_student = get_older(student1, student2);
    printf("Starszy student: ");
    print_student(older_student);

    printf("\n");
    return 0;
}
