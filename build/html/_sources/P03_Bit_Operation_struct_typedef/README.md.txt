# 03 - Bit Operationen, Struct, Typedef


## 1. Bit Operationen

![](./135oALYhkYyXB2aG0F-qrwA.jpeg)


Bit Operationen sind allgegenwärtig in den Computer-Wissenschaften und finden in vielen Disziplinen Anwendung. Folgend ein kleiner Auszug aus den wichtigsten Themen:
- **Bit Felder**: Sind die effizienteste Art, etwas darzustellen, dessen Zustand durch mehrere "wahr" oder "falsch" definiert werden kann. Besonders auf Systemen mit begrenzten Ressourcen sollte jede überflüssige Speicher-Allozierung vermieden werden.

  Beispiel:
  ```c
  // primary colors
  #define BLUE  0b100
  #define GREEN 0b010
  #define RED   0b001

  // mixed colors
  #define BLACK   0 /* 000 */
  #define YELLOW  (RED | GREEN) /* 011 */
  #define MAGENTA (RED | BLUE) /* 101 */
  #define CYAN    (GREEN | BLUE) /* 110 */
  #define WHITE   (RED | GREEN | BLUE) /* 111 */
  ```
[https://de.wikipedia.org/wiki/Bitfeld](https://de.wikipedia.org/wiki/Bitfeld)

- **Kommunikation**: 
  - **Prüfsummen/Paritätsbit**: Übertragungsfehler und Integrität      können bis zu einem definiertem Grad erkannt werden. Je nach   Komplexität der Berechnung können mehrere Fehler erkannt oder auch korrigiert werden. 
[https://de.wikipedia.org/wiki/Parit%C3%A4tsbit](https://de.wikipedia.org/wiki/Parit%C3%A4tsbit), [https://de.wikipedia.org/wiki/Pr%C3%BCfsumme](https://de.wikipedia.org/wiki/Pr%C3%BCfsumme)
  - **Stoppbit**: Markieren bei asynchronen seriellen Datenübertragungen das Ende bzw. Start eines definierten Blocks.
[https://de.wikipedia.org/wiki/Stoppbit](https://de.wikipedia.org/wiki/Stoppbit)
  - **Datenflusssteuerung**: Unterschiedliche Verfahren, mit denen die Datenübertragung von Endgeräten an einem Datennetz, die nicht synchron arbeiten, so gesteuert wird, dass eine möglichst kontinuierliche Datenübermittlung ohne Verluste erfolgen kann.
[https://de.wikipedia.org/wiki/Datenflusssteuerung](https://de.wikipedia.org/wiki/Datenflusssteuerung)
  - ...

- **Datenkompression**: Bei der Datenkompression wird versucht, redundante Informationen zu entfernen. Dazu werden die Daten in eine Darstellung überführt, mit der sich alle – oder zumindest die meisten – Information in kürzerer Form darstellen lassen.
[https://de.wikipedia.org/wiki/Datenkompression](https://de.wikipedia.org/wiki/Datenkompression)
- **Kryptographie**: Konzeption, Definition und Konstruktion von Informationssystemen, die widerstandsfähig gegen Manipulation und unbefugtes Lesen sind. [https://de.wikipedia.org/wiki/Verschl%C3%BCsselung](https://de.wikipedia.org/wiki/Verschl%C3%BCsselung)
- **Grafik-Programmierung**: XOR (oder ^) ist hier besonders interessant, weil eine zweite Eingabe derselben Eingabe die erste rückgängig macht (ein Beispiel dazu weiter unten: "Variablen tauschen, ohne Dritt-Variable
"). Ältere GUIs verwendeten dies für die Hervorhebung von Auswahlen und andere Überlagerungen, um kostspielige Neuzeichnungen zu vermeiden. Sie sind immer noch nützlich in langsamen Grafikprotokollen (z. B. Remote-Desktop). 

### 1.1 Übungen

#### 1. Basis Operationen
Manipulationen von einzelnen Bits gehören zu den Basis Operationen und dienen als Grundlagen um weitere komplexere Konstrukte zu schaffen. Verfollständigen sie folgendes Beispiel mit den drei Basis Operationen:
```c
#include <stdlib.h>

int main() {
  unsigned int number;
  unsigned int bit = 3; // bit at position 3

  // Setting a bit
  number = ...; // solution: number |= 1 << bit;
  
  // Clearing a bit
  number = ...; // solution: number &= ~(1 << bit);
  
  // Toggling a bit
  number = ...; // solution; number ^= 1 << bit;
  
  return EXIT_SUCCESS;
}
```

#### 2. Variablen tauschen (ohne Dritt-Variable)
Zwei Variablen zu vertauschen scheint ein einfach lösbares Problem zu sein. Eine offensichtliche Variante wäre mittels einer temporären Variablen:
```c
#include <stdlib.h>
#include <stdio.h>

int main(){
  int a = 3;
  int b = 4;
  printf("a: %d; b: %d\n", a, b);
  
  int temp = a;
  a = b;
  b = temp;
  
  printf("a: %d; b: %d\n", a, b);
  return EXIT_SUCCESS;
}
```

Es gibt aber auch eine Variante, die ohne zusätzliche Variable auskommt. Dabei wird die Tatsache, dass eine zweite XOR Operation eine erste XOR Operation rückgängig macht:

*0011 XOR 0100 = 0111*

*0111 XOR 0100 = 0011*

Somit kommt man von einem XOR Resultat (*0111*) wieder auf beide Anfangs Operanden zurück indem man einfach ein zweites Mal mit einem Operanden eine XOR Verknüpfung macht. Damit kann ein Operand als Zwischenspeicher dienen und man muss nicht extra eine Zusatzvariable verwenden.

Überlegen sie sich wie sie damit zwei Variablen vertauschen können ohne Zusatzvariable:
```c
#include <stdlib.h>
#include <stdio.h>

int main(){
  int a = 3;
  int b = 4;
  printf("a: %d; b: %d\n", a, b);
  

  ...

  /* Solutions: 
          // a == 0011; b == 0100
  a ^= b; // a == 0111; b == 0100
  b ^= a; // a == 0111; b == 0011
  a ^= b; // a == 0100; b == 0011
  */
  
  printf("a: %d; b: %d\n", a, b);
  return EXIT_SUCCESS;
}
```

#### 3. Lower- / Uppercase
```c
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

  return EXIT_SUCCESS;
}
```

#### 4. Prüfen auf 2-er Potenz
```c
#include <stdio.h>
#include <stdlib.h>

int main(){
  int a=32;
  if(a > 0 && (a & (a - 1)) == 0){
    printf("%d is a power of 2", a);
  }
  return EXIT_SUCCESS;
}
```
___
## 2. Struct & typedef

### 2.1 Übungen

#### 1. Bit Operationen Rechner
 - Bitweise Operationen mit 2 Operanden
 - Rechnung wird als ein String über scanf dem Programm übergeben
	- String wird in Token zerstückelt und in struct gespeichert:
	  ```c
	  typedef struct {
	    unsigned int operand_1;
	    unsigned int operand_2;
	    char operation;
	  } Expression;
	   ```
   - Ausgabe in 3 verschiedenen Formaten:
     ```
	   Bin:
	   0000'0000'0000'0001
	 & 0000'0000'0000'0011
	   -------------------
	   0000'0000'0000'0001
       
       Hex
       0x01 & 0x03 = 0x01

       Dec
       1 & 3 = 1
	   ```

___
## 4. Bewertung

Die gegebenenfalls gestellten Theorieaufgaben und der funktionierende Programmcode müssen der Praktikumsbetreuung gezeigt werden. Die Lösungen müssen mündlich erklärt werden können.
| Aufgabe | Kriterium | Gewicht |
| :-- | :-- | :-- |
| alle | Sie können das funktionierende Programm inklusive funktionierende Tests demonstrieren und erklären. |  |
| gibIntWert | Eingabe, Bereichsüberprüfung korrekt | 1 |
| istSchaltjahr | Funktion korrekt | 1 |
| TageProMonat | Funktion korrekt | 1 |
| Aufgabe 2 | Fehlenden Teile ergänzt und lauffähig | 1 |
