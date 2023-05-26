#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int (*CMP)(const void *, const void *);
typedef void (*PRINT)(const void *);

typedef struct _Node
{
    void *data;
    struct _Node *next;
} Node;

typedef struct _SortedList
{
    Node *head;
} SortedList;

void initialize_list(SortedList *list);

void add(SortedList *list, void *data, CMP cmp);

void print_list(const SortedList *list, PRINT print);

void remove_data(SortedList *list, CMP cmp, void *data);

void remove_all(SortedList *list);

void *get_data(const SortedList *list, CMP cmp, const void *data);

#endif
