/**
 *  P02 Praktikum
 *
 *  Das Programm liest einen Monat (1-12) und ein Jahr (1600-2400) ein und
 *  gibt die Anzahl der Tage dieses Monats aus.
 *
 *  @author Gerrit Burkert, Adaptation bazz
 *  @version 15-FEB-2013, 16-OCT-2017, 17-OCT-2019, 16-FEB-2022
 */

#include <stdio.h>
#include <stdlib.h>

#define ERROR_IN_MONTH 1
#define ERROR_IN_YEAR 2

///// Student Code
int gibIntWert(char* input, int min, int max);
int istSchaltjahr(int year);
int tageProMonat(int year, int month);

typedef enum {JAN = 1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OCT, NOV, DEC} Month;

int gibIntWert(char* input, int min, int max){
    
    if(input == "Monat"){
        int month;
        printf("Bitte gibt den Monat ein ( %d-%d )\n", min, max);
        scanf("%d", &month); 
        
        if (month < min || month > max){
            return -1;
        }
        
        return month;
    } else if (input == "Jahr") {
        int year;
        printf("Bitte gibt das Jahr ein ( %d-%d )\n", min, max);
        scanf("%d", &year); 
        
        if (year < min || year > max){
            return -1;
        }
        
        return year;
    }
}

int istSchaltjahr(int year){
    if(year % 4 == 0 && year % 100 == 0 && year % 400 == 0){
        return 1;
    } else {
        return 0;
    }
}

int tageProMonat(int year, int month){
    if(month == FEB){
        if(istSchaltjahr(year)){
            return 29;
        }
        return 28;        
    } else if (month == JAN || month == MAR || month == MAI || month == JUL 
    || month == AUG || month == OCT || month == DEC){
        return 31;    
    } else {
        return 30;
    }
}




///// END Student Code


int main (int argc, char *argv[]) {
    
    int monat, jahr;
     
    //  Monat einlesen und Bereich ueberpruefen
    monat = gibIntWert("Monat", 1, 12);
    if(monat == -1){
        printf("Der Monat liegt nicht im richtigen Bereich!\n");
        return ERROR_IN_MONTH;
    }
    jahr  = gibIntWert("Jahr", 1600, 9999);
    if(jahr == -1){
    printf("Das Jahr liegt nicht im richtigen Bereich!\n");
        return ERROR_IN_YEAR;
    }
	
    //  Ausgabe zum Test
    printf("Monat: %d, Jahr: %d \n", monat, jahr);    
    
    //  Ausgabe zum Test (hier mit dem ternaeren Operator "?:")
    printf("%d ist %s Schaltjahr\n", jahr, istSchaltjahr(jahr) ? "ein" : "kein");

    // Ausgabe
    printf("Der Monat %02d-%d hat %d Tage.\n", monat, jahr, tageProMonat(jahr, monat));
   
    return 0;
}
