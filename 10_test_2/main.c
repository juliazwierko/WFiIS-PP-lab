#include "list.h"
#include "main.h"

int main(void)
{
    Student student1 = {
        .last_name = "Kowalski",
        .first_name = "Jan",
        .age = 20,
        .status = STUDENT,
        "ul. Reymonta 17, Krakow"};
    Student student2 = {
        "Marek",
        "Nowak",
        23,
        GRADUATE,
        "ul. Czarnowiejska 1, Krakow"};
    Student student3 = {
        "Anna",
        "Barcik",
        19,
        REMOVED,
        "os. Mlodych 15d/7, Krakow"};

    SortedList list;
    initialize_list(&list);

    add(&list, &student1, students_cmp); // Dodajemy student1 do listy.
    add(&list, &student2, students_cmp); // Dodajemy student2 do listy.
    add(&list, &student3, students_cmp); // Dodajemy student3 do listy.

    Student student4 = student1;
    strcpy(student4.address, "ul. Reymonta 17, Krak"); // Adres ucięty w stosunku do oryginalnego student1.
    add(&list, &student4, students_cmp);               // Dodajemy student4 do listy.

    print_list(&list, print_student); // Wypisywanie: czworo studentow posortowanych alfabetycznie.

    Student to_found = student1;
    Student *found = get_data(&list, students_cmp, &to_found); // Szukamy obiektu identycznego ze student1
    if (found != NULL)
    {
        printf("\nZnaleziono:\n");
        print_student(found);
    }
    else
        printf("\nNie znaleziono.\n");
    printf("\n");

    to_found.age++; // Zwiększony wiek - takiego studenta nie ma na liście.
    found = get_data(&list, students_cmp, &to_found);
    if (found != NULL)
    {
        printf("\nZnaleziono:\n");
        print_student(found);
    }
    else
        printf("\nNie znaleziono.\n");
    printf("\n");

    remove_data(&list, students_cmp, &student4); // Usuwanie studenta.
    remove_data(&list, students_cmp, &student4); // Próba powtórnego usunięcia: brak zmian na liście, bo już nie ma takiego obiektu.
    print_list(&list, print_student);            // Wypisanie listy po usunięciu jednego studenta.

    remove_all(&list);                // Usuwamy wszystko.
    print_list(&list, print_student); // Wypisanie pustej listy.
    return 0;
}

int students_cmp(const void *a, const void *b)
{
    const Student *st1 = a;
    const Student *st2 = b;
    int to_return = 0;
    if ((to_return = strcmp(st1->last_name, st2->last_name)))
        return to_return; // Alfabetycznie po nazwisku.
    if ((to_return = strcmp(st1->first_name, st2->first_name)))
        return to_return; // Jeśli nazwiska te same: alfabetycznie po imieniu, itd.
    if (st1->age < st2->age)
        return -1;
    if (st1->age > st2->age)
        return 1;
    if ((to_return = strcmp(st1->address, st2->address)))
        return to_return;
    return to_return; // 0, bo identyczne (pomijając status).
}

void print_student(const void *st)
{
    if (st == NULL)
        return;
    const Student *student = st;
    printf("Dane studenta: %s %s, wiek: %u, adres: %s, status: ", student->first_name, student->last_name, student->age, student->address);
    switch (student->status)
    {
    case STUDENT:
        printf("student.\n");
        break;
    case GRADUATE:
        printf("absolwent.\n");
        break;
    case REMOVED:
        printf("usuniety z listy studentow.\n");
        break;
    default:
        printf("NIEZNANY STATUS.\n");
    }
}
