#include "stringSort.h"

int main() {
    dictionary_t dictionary;
    
    //get 10 words user input
    printf("Enter %d words with a max length of %d letters: \n",NR_OF_WORDS ,WORD_SIZE);
    int counter = 0;
    
    //scan words
    do {
        //scan word itself
        do {
            printf("%d > ", counter+1);
			scanf("%s", dictionary[counter]);
			
			if(strlen(dictionary[counter]) > WORD_SIZE) printf("The word you entered exceeded the maximum length of %d letters. Please enter a new one\n", WORD_SIZE);
			
			convert_to_uppercase(dictionary[counter]);
        } while (strlen(dictionary[counter]) == 0 || strlen(dictionary[counter]) > WORD_SIZE );
        
        if(check_for_duplicates(dictionary[counter], dictionary, counter) == DUPLICATE_EXISTS){
            printf("The word you entered already exists, please enter another one\n");
            } else {
                ++counter;
                }
    } while (counter < NR_OF_WORDS && strcmp(dictionary[(counter-1)], STOP) != 0);
    
    //sort array alphabetically
	sort_alphabetically(dictionary, counter);
	
	//display the sorted array
	printf("_______________________________________\n");
	printf("Sorted Array: \n");
	print_words(dictionary, counter);
	
	return EXIT_SUCCESS;
}

void convert_to_uppercase(word_t word){
    for(int i = 0; i < WORD_SIZE && word[i] != '\0'; ++i){
        word[i] = word[i] & '_';
    }
}


int check_for_duplicates(word_t word, dictionary_t dictionary, int position){
	if (position == 0) return NO_DUPLICATES;
	
	for(int i = 0; i<position; ++i){
		if(strcmp(word, dictionary[i]) == 0) return DUPLICATE_EXISTS;
	}
	
	return NO_DUPLICATES;
}

void print_compare_word(word_t word, int position){
	printf("________________________\n");
	printf("word[%d] = %s\n", position, word);
	printf("________________________\n");
}

void sort_alphabetically(dictionary_t dictionary, int length){
    for(int i = 0; i < length - 1; i++){
        for(int j=i+1; j < length; j++){
            printf("compare with [%d]: %s = %d\n",j, dictionary[j], strcmp(dictionary[i], dictionary[j]));
            
            if(strcmp(dictionary[i],dictionary[j])>0){
				
				word_t temp;
				strcpy(temp,dictionary[i]);
				strcpy(dictionary[i],dictionary[j]);
				strcpy(dictionary[j],temp);
			}
        }
    }
}

void print_words(dictionary_t dictionary, int length){
	for (int i = 0; i<length; ++i){
		printf("%d: %s\n",i+1, dictionary[i]);
	}
}

