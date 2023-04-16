#ifndef PERSON_H
#define PERSON_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define NAME_MAX_LEN 20
typedef struct {
    char name[NAME_MAX_LEN];
    char first_name[NAME_MAX_LEN];
    int age;
} person_t;


int person_compare(const person_t *a, const person_t *b);

int check_name(const char *name);
int check_age(const person_t *person, int is_number);

void scan_name(person_t *person);
void scan_first_name(person_t *person);
void scan_age(person_t *person);

void format_person(person_t *person);

void print_person(const person_t *person);
#endif
