#ifndef STRING_SORT_H
#define STRING_SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NR_OF_WORDS 10
#define WORD_SIZE 20
#define NO_DUPLICATES 0
#define DUPLICATE_EXISTS 1
#define STOP "ZZZ"

typedef char word_t [WORD_SIZE];

typedef char dictionary_t [NR_OF_WORDS][WORD_SIZE];

void convert_to_uppercase(word_t word);
int check_for_duplicates(word_t word,  dictionary_t dictionary, int position);
void sort_alphabetically(dictionary_t dictionary, int length);
void print_words(dictionary_t dictionary, int length);
#endif
