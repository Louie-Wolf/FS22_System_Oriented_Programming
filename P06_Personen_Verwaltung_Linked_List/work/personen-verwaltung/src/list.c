#include "list.h"

node_t *head = NULL;

int list_find(person_t *person){
    int i = 0;
    node_t *link = head;
    while(link != NULL) {
        if (person_compare(person, &link->content) == 0) {
            return i + 1;
        }
        link = link->next;
        i++;
    }
    return -1;
}

void list_insert(person_t *person){
    node_t *newNode = malloc(sizeof(node_t));
    newNode->content = *person;
    newNode->next = NULL;
    
    if(head == NULL){
        head = newNode;
        return;
    }
    
    node_t *link = head;
    node_t *linkPrev = NULL;
    
    while(link != NULL){
        if(person_compare(&link->content, person) > 0){
            if (link == head) {
                newNode->next = link;
                head = newNode;
                return;
            } else {
                newNode->next = linkPrev->next;
                linkPrev->next = newNode;
                return;
            }
        }
        linkPrev = link;
        link = link->next;
    }
    
    linkPrev->next = newNode;
}

void list_remove(person_t *person){
    node_t *link = head;
    node_t *linkPrev = NULL;
    while(link != NULL) {
        if (person_compare(&link->content, person) == 0) {
            if (link == head) {
                head = link->next;
                free(link);
                return;
            } else {
                linkPrev->next = link->next;
                free(link);
                return;
            }
        }
        linkPrev = link;
        link = link->next;
    }
}

void list_clear() {
    node_t *link = head;
    while(link != NULL) {
        node_t *next = link->next;
        free(link);
        link = next;
    }
    head = NULL;
}

void list_show(){
    (void) printf("+----------------------+----------------------+------+\n");
    (void) printf("|         Name         |       Firstname      |  Age |\n");
    (void) printf("+----------------------+----------------------+------+\n");

    node_t *link = head;
    while(link != NULL) {
        printf("| %20s | %20s | %4u |\n", link->content.name, link->content.first_name, link->content.age);
        link = link->next;
    }

    printf("+----------------------+----------------------+------+\n");
}


