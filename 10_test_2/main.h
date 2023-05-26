#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define MAX 50

typedef enum
{
    GRADUATE = 2,
    STUDENT = 1,
    REMOVED = -1
} student_status;

typedef struct
{
    const char *first_name;
    const char *last_name; 
    unsigned short age;
    student_status status;
    char address[MAX];
} Student;

int students_cmp(const void *a, const void *b);

void print_student(const void *st);

#endif


