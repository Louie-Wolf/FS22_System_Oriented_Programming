#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "person.h"

typedef struct node{
    person_t content;       //person of this node
    struct node *next;      //pointer to next node
} node_t;

int list_find(person_t *person);
void list_insert(person_t *person);
void list_remove(person_t *person);
void list_clear();
void list_show();


#endif
