#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "list.h"

int main() {
    const char *filename = "students.bin";

    // a) Otwieranie pliku binarnego w trybie odczytu
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Błąd otwarcia pliku do odczytu.\n");
        return 1;
    }

    // b) Wczytywanie danych ze pliku do tablicy struktur Student
    Student *students = NULL; 
    int num_students = 0;      

    while (true) {
        Student student;
        size_t items_read = fread(&student, sizeof(Student), 1, file);

        if (items_read == 0) {
            if (feof(file)) {
                // Koniec pliku
                break;
            } else {
                // Błąd odczytu
                fprintf(stderr, "Błąd odczytu pliku.\n");
                fclose(file);
                free(students);
                return 1;
            }
        }
        Student *temp = realloc(students, (num_students + 1) * sizeof(Student));
        if (temp == NULL) {
            fprintf(stderr, "Błąd alokacji pamięci.\n");
            fclose(file);
            free(students);
            return 1;
        }
        students = temp;
        students[num_students] = student;
        num_students++;
    }
    fclose(file);

    // c) Wypisywanie danych studentów z tablicy
    printf("Dane studentów:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Imię: %s\n", students[i].first_name);
        printf("Nazwisko: %s\n", students[i].last_name);
        printf("Wiek: %u\n", students[i].age);
        printf("Email: %s\n", students[i].email);
        printf("\n");
    }

    // d) Zwolnienie pamięci zaalokowanej dynamicznie
    free(students);
    return 0;
}
// gcc -o sainz.c verstappen.c list.c
// ./sainz.c 10 students.bin
// ->Duza losowa litera: W
// ->Mala losowa litera: e

// ->Losowe imię/nazwisko: Whvbxnfbyjpzndaxk

// ->Random email: SGDZE@@student.agh.edu.pl

// Losowy student:
// Dane studenta: Waamsaanuxsksnzdwctvopzyrwsawneh Eekamuonjbczwqaswcmsxmtizzwtjzvwuddygfpalmvbc, wiek: 26, adres: XHXVIKJZWNXGHWDMCZOPIBHXM@@student.agh.edu.pl
