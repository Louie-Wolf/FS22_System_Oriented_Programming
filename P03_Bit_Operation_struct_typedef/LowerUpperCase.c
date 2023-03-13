#include <stdlib.h>
#include <stdio.h>

int main(){
  char word[8] = "sREedEv";
  char *wordptr = &word[0];

  while(wordptr < &word[7]) {
    printf("UPPERCASE: %c\n", *wordptr & '_'); // converts the char into uppercase regardless of the current casing
    printf("LOWERCASE: %c\n", *wordptr | ' '); // converts the char into lowercase regardless of the current casing
    wordptr++;
  }
  
  //Begründung mit & _ Verknüfpung wird der Wert 32 subtrahiert. Auf sich selbst bleibt es gleich.
  //Begründung mit | SPACE Verknüpfung wid der Wert 32 addiert. Auf sich selbst bleibt es gleich.
  
  //115 
  //1110011
  //95
  //1011111
  //83
  //1010011

  return EXIT_SUCCESS;
}
