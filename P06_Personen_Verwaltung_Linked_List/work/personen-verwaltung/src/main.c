/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


#define NR_ACTIONS 5
typedef enum{
    INSERT = 0,
    REMOVE,
    SHOW,
    CLEAR,
    END
} action_t;

char action_id[] = {'I', 'R', 'S', 'C', 'E'};

char *program_title = "Personenverwaltungsapperaturenautomatdings";
char *insert_title = "Insert person into list";
char *remove_title = "Remove person from list";

action_t get_action(char action_id);
char convert_to_uppercase(char letter);
void scan_person(person_t *person);
void print_title(char *title);
/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an expression syntax error.
 */
int main(int argc, char* argv[])
{
	// BEGIN-STUDENTS-TO-ADD-CODE
    action_t action=INSERT;
    
    while(action != END){
        print_title(program_title);
		(void) printf("[I]nsert, [R]emove, [S]how, [C]lear, [E]nd: ");
		fflush(stdin);
		char user_input = getchar();
		action = get_action(user_input);
		
		switch(action){
		    case INSERT:
		    {
				person_t person;

				print_title(insert_title);
				scan_person(&person);
				if(list_find(&person) > -1){
				    (void) printf("Person already exists in list.\n");
				} else {
					list_insert(&person);
					print_person(&person);
					(void) printf(" was added to list.\n");
				}
				break;
			}
			case REMOVE: 
			{
				person_t person;

				print_title(remove_title);
				scan_person(&person);
				if(list_find(&person) < 0){
				    (void) printf("No such entry exists in list.\n");
				}
				else {
					list_remove(&person);
					print_person(&person);
					(void) printf(" was removed from list.\n");
				}
				break;
			}
			case SHOW: 
			{
				list_show();
				break;
			}
			case CLEAR: 
			{
				list_clear();
				break;
			}
			case END: break;
			default:
			{	
				printf("\n");
				break;
			}
		}
    }
	// END-STUDENTS-TO-ADD-CODE
    return EXIT_SUCCESS;
}

action_t get_action(char id){
	char id_upper = convert_to_uppercase(id);
	for(int i=0; i<NR_ACTIONS; ++i){
		if(id_upper == action_id[i]) return i;
	}
	return NR_ACTIONS;
}

char convert_to_uppercase(char letter){
	char upper = letter & '_';
	return upper;
}

void scan_person(person_t *person) {
    fflush(stdin);
	scan_name(person);
	scan_first_name(person);
	scan_age(person);
	format_person(person);
}

void print_title(char *title){
	(void) printf("%s\n", title);
	(void) printf("%s\n","----------------------------");
}
