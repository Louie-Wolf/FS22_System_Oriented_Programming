#include <stdio.h>

int main(){
    int i = 0;
    int counter = 0;
    int counterSpace = 0;
    int counterWords = 0;
    char currentChar;
    char inputString[50];
    printf("Enter the characters:\n");
    
    do
    {
        currentChar = getchar();
        
        inputString[i] = currentChar;
        if(currentChar != '\n' && currentChar != '\t' && currentChar != ' '){
           counter +=1;
           counterSpace = 0;
        } else {
            counterSpace++;
            if(counterSpace == 1){
                counterWords++;
            }
        }
        
        i++;
        
    } while (currentChar != '\n');
    
    printf("Entered characters are: %d\n", counter);
    printf("Entered words are: %d\n", counterWords);
    //printf("The string was: %s\n", inputString);
    return 0;    
}
