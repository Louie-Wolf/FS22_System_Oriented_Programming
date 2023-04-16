#include "person.h"

int person_compare(const person_t *a, const person_t *b){
    if(strcmp(a->name, b->name) != 0){
        return 1;
    }
    
    if(strcmp(a->first_name, b->first_name) != 0){
        return 1;
    }
    
    return a->age - b->age;
}

int check_name(const char *name){
    if(strlen(name) > NAME_MAX_LEN){
        (void) printf("The length of the entered name exceeded the maximum (%d) of the allowed length.\n", NAME_MAX_LEN);
        return 0;
    }
    return 1;
}

int check_age(const person_t *person, int is_number){
    if(is_number < 1){
        (void) printf("The age must be a number. \n");
        return 0;
    }
    if(person->age > 150){
        (void) printf("The age you entered '%d' is invalid\n", person->age);
        return 0;
    }
    (void) printf("Age is valid!\n");
    return 1;
}

void scan_name(person_t *person){
    (void) printf("Name: ");
    
    scanf("%s", person->name);
    
    if(!check_name(person->name)){
        scan_name(person);
    }
}

void scan_first_name(person_t *person){
    (void) printf("First name: ");
    scanf("%s", person->first_name);
    if(!check_name(person->first_name)){
        scan_name(person);
    }
}

void scan_age(person_t *person){
    char input[256];
    int is_number;
    do {
        printf("Age: ");
        fgets(input, sizeof(input), stdin);
        is_number = sscanf(input, "%d", &person->age);
    } while(!check_age(person, is_number));
}

void format_person(person_t *person){
    person->name[0] = person->name[0] & '_';
    person->first_name[0] = person->first_name[0] & '_';
    
    for(int i = 1; i < strlen(person->name); ++i){
        person->name[i] = person->name[i] | ' ';
    }
    
    for(int i = 1; i < strlen(person->first_name); ++i){
        person->first_name[i] = person->first_name[i] | ' ';
    }
}

void print_person(const person_t *person){
    (void) printf("Person: %s, %s %d", person->name, person->first_name, person->age);
}

