#include <stdio.h>

int main(){
    int i = 0;
    int counter = 0;
    char currentChar;
    char inputString[50];
    printf("Enter the characters\n");
    
    //V1
    do
    {
        currentChar = getchar();
        
        inputString[i] = currentChar;
        if(currentChar != '\n' && currentChar != '\t' && currentChar != ' '){
           counter +=1;
        }
        
        i++;
        
    } while (currentChar != '\n');
    
    printf("Entered characters are: %d", counter);
    printf("The string was: %s", inputString);
    return 0;    
}
