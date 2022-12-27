# C89 Notes

## Table of contents

* [Built-in Types](#built-in)
* [Operatori aritmetici](#operatori-aritmetici)
* [Istruzioni ingresso ed uscita](#istruzioni-ingresso-ed-uscita)
* [Struttura di un programma in C](#struttura-di-un-programma-in-c)
* [Operatori ed espressioni logiche](#operatori-ed-espressioni-logiche)
* [Costanti](#costanti)
* [Array](#array)
    * [Array di caratteri e stringhe](#array-di-caratteri-e-stringhe)
    * [Array multidimensionali](#array-multidimensionali)
    * [Struct vs Array](#struct-vs-array)
* [Puntatori e programmazione modulare](#puntatori-e-programmazione-modulare)

## Built-in Types

I data types predefiniti di C89 sono:

|Data type|Descrizione|
|--|--|
|`char`|Permette di contenere un carattere della tabella ASCII che corrisponde ad un intero [ 0, 250 ]|
|`int`|Numeri interi|
|`float`|Numeri decimali a singola precisione|
|`double`|Numeri decimali a doppia precisione|

Sintassi generale per dichiarazione singola `keywordTipo nomeVariabile1;` e dichiarazione multipla 
`keywordTipo nomeVariabile1, nomeVariabile2;`.

```c
int socialSecurityNumber;
int age, numOfPeople; 
```

É possibile inizializzare simultaneamente alla dichiarazione `keywordTipo nomeVariabile1 = valIniziale;`.

```c
int carPlate = 634, numOfCars = 11;
```

> Ogni variabile deve essere **dichiarata** prima di essere utilizzata.

I caratteri alfanumerici vanno racchiusi tra apici singoli:

```c
char randomAlhpaNum = '2';
randomAlphaNum = 'a';
randomAlphaNum = 'A';
randomAlphaNum = 'z';
```

## Operatori aritmetici

La divisione con l'operatore `/` assume diversi significati a seconda degli operandi. Fra tipi `int` calcola il quoziente troncato della parte frazionaria, mentre fra `float` calcola il quoziente compreso di parte frazionaria. Altri operatori built-in sono `+` `-` `*` `%`.

> `%` vs `/` » L'operatore aritmetico modulo (`%`) calcola una divisione troncando il quoziente, ad esempio `17 % 5` sarà diverso da `17 / 5`, i risultati sono rispettivamente `2` e `3`.

## Istruzioni ingresso ed uscita

Per la scrittura su standard output si utilizza `printf()` mentre per la lettura da standard input viene usato `scanf()`.

```c
int a = 3, b = 2;

printf("Hello World\n");
scanf("%d%s", &someInteger, &someString); 
/* 'someInteger' e 'someString' dichiarate in precendenza! */
printf("\n %d + %d = %d", a, b, a + b);
```

|Stringa di controllo|Descrizione|Carattere di stampa|Carattere di conversione|
|--|--|:--:|:--:|
|`\n`|Carriage return|○|
|`\t`|Tab|○|
|`%d`|Intero decimale||○|
|`%f`|Numero reale||○|
|`%c`|Carattere||○|
|`%s`|Sequenza di caratteri (stringa)||○|

## Struttura di un programma in C

```c
#include <stdio.h>

int main(int argc, char* argv[]) {
    
    print("Hello World!\n");
    return 0;
}
```

> La libreria `stdio.h` (standard input/output) contiene funzioni per la gestione dell'input e dell'output fra cui `printf()` e `scanf()`.

**Esercizio** » Scrivere un programma che prenda in ingresso una temperatura in Fahrenheit e la trasformi in Celsius.

```c
#include <stdio.h>

int main(int argc, char* argv[]) {
    
    int celsiusTemp; float fahrTemp;
    
    printf("Inserire valore della temperatura in gradi Fahrenheit: ");
    scanf("%f", &fahrTemp);
    
    celsiusTemp = (fahrTemp - 32) / 1.8;
    
    printf("Gradi Celsius: %d\n", celsiusTemp);
    
    return 0;
}
```

## Operatori ed espressioni logiche

|Operatore|Descrizione|Operatore logico|Operatore relazionale|
|--|--|:--:|:--:|
|`==`|Equal to||○|
|`!=`|Not equal to||○|
|`>` `>=`|Greater, greater and equal||○|
|`<` `<=`|Less, less and equal||○|
|`!`|NOT|○|
|`&&`|AND|○|
|`\|\|`|OR|○|

La precedenza degli operatori è la seguente: `! + - &` > `* / %` > `< <= >= >` > `== !=` > `&&` > `||` > `=`. É possibile inoltre fare un assegnazione di tipo logico alle variabili in modo tale che una volta mettendo solamente il valore della variabile in un'unica espressione caratterizzata solamente dall'identifier della variabile, vale che per ogni valore diverso da zero assegnatovi l'espressione è vera.

```c
int flag;

flag = 0; /* falso */
flag = 1; /* vero */
flag = 25; /* vero */
flag = 239; /* vero */
flag = (23 > 21) /* vero */
```

>NB: da usare solo con le variabili di tipo `int`.

Durante la costruzione di tabelle di verità si noti che per *n* variabili logiche si hanno 2<sup><em>n</em></sup> righe. Di seguito le tabelle di verità delle espressioni logiche elementari:

**NOT**

|A|!A|
|:--:|:--:|
|`0`|**`1`**|
|`1`|**`0`**|

> Il NOT è un operatore unario, che prende in ingresso una sola espressione.

**AND**

|A|B|A && B|
|:--:|:--:|:--:|
|`0`|`0`|**`0`**|
|`0`|`1`|**`0`**|
|`1`|`0`|**`0`**|
|`1`|`1`|**`1`**|

> A && B è vero se e solo se sia A che B sono vere.

**OR**

|A|B|A \|\| B|
|:--:|:--:|:--:|
|`0`|`0`|**`0`**|
|`0`|`1`|**`1`**|
|`1`|`0`|**`1`**|
|`1`|`1`|**`1`**|

> A \|\| B è vero se almeno una delle due è vera. NB: non è exclusive OR (XOR).

Esempio di tabella di verità composta:

|A|B|C|!B|A && !B|A && !B \|\| C|
|:--:|:--:|:--:|:--:|:--:|:--:|
|`0`|`0`|`0`|`1`|`0`|**`0`**|
|`0`|`0`|`1`|`1`|`0`|**`1`**|
|`0`|`1`|`0`|`0`|`0`|**`0`**|
|`0`|`1`|`1`|`0`|`0`|**`1`**|
|`1`|`0`|`0`|`1`|`1`|**`1`**|
|`1`|`0`|`1`|`1`|`1`|**`1`**|
|`1`|`1`|`0`|`0`|`0`|**`0`**|
|`1`|`1`|`1`|`0`|`0`|**`1`**|

Leggi di De Morgan:

**!(A && B) == !A \|\| !B**

|A|B|A && B|!(A && B)|
|:--:|:--:|:--:|:--:|
|`0`|`0`|`0`|**`1`**|
|`0`|`1`|`0`|**`1`**|
|`1`|`0`|`0`|**`1`**|
|`1`|`1`|`1`|**`0`**|

|A|B|!A|!B|!A \|\| !B|
|:--:|:--:|:--:|:--:|:--:|
|`0`|`0`|`1`|`1`|**`1`**|
|`0`|`1`|`1`|`0`|**`1`**|
|`1`|`0`|`0`|`1`|**`1`**|
|`1`|`1`|`0`|`0`|**`0`**|

> Le due tabelle di verità verificano l'equivalenza !(A && B) == !A \|\| !B.

**!(A \|\| B) == !A && !B**

|A|B|A \|\| B|!(A \|\| B)|
|:--:|:--:|:--:|:--:|
|`0`|`0`|`0`|**`1`**|
|`0`|`1`|`1`|**`0`**|
|`1`|`0`|`1`|**`0`**|
|`1`|`1`|`1`|**`0`**|

|A|B|!A|!B|!A && !B|
|:--:|:--:|:--:|:--:|:--:|
|`0`|`0`|`1`|`1`|**`1`**|
|`0`|`1`|`1`|`0`|**`0`**|
|`1`|`0`|`0`|`1`|**`0`**|
|`1`|`1`|`0`|`0`|**`0`**|

> Le due tabelle di verità verificano l'equivalenza !(A \|\| B) == !A && !B.

In C vi sono costrutti condizionali come `if`, `switch` e costrutti iterativi come `while`, `do while` e `for`.

Sintassi del costrutto `if`:

```c
if(expression) {
    
    corpo_if;

} else {
    
    corpo_else;
}
```
> NB: `else` è opzionale.

Sintassi costrutti `if` ed `else if` nested.

```c
if(expressionOne) {

    someInstruction;
    if(nestedExpression) {

        nestedInstruction;
    
    } else {

        if(elseBranchExpressionNested) {
            
            doSomething;
        }
        anotherNestedInstruction;
    }

} else if(elseBranchExpression)  { /* another form for 'else if' */

    doAnything;
}
```

**Esercizio** » Scrivere un programma che prenda in ingresso un intero positivo e che determini se il numero corrisponda ad un anno bisestile o meno.

```c
#include <stdio.h>

int main(int argc, char* argv[]) {
    
    int inputYear;
    
    printf("Inserire l'anno: ");
    scanf("%d", &inputYear);
    
    if( (((inputYear % 4) == 0) && ((inputYear % 4) != 100)) || 
        ((inputYear % 400) == 0) ) {
        
        printf("%d è un anno bisestile!", inputYear);
    
        
    } else {printf("%d NON è un anno bisestile!", inputYear);}
    
    return 0;
}
```

Sintassi del costrutto iterativo `while`:

```c
while(expression) {

    someInstruction;
}
```

**Esercizio** » Stampa i primi 100 numeri naturali pari.

```c
#include <stdio.h>

int main(int argc, char* argv[]) {
    
    int indexLoop = 1;
    
    while(indexLoop <= 50) {
        
        printf("%d\n", indexLoop*2);
        indexLoop++;
    }
    
    return 0;
}
```

**Esercizio** » Eseguire la somma e la media di una sequenza di numeri naturali inseriti dall'utente e continuare finchè l'utente inserisce 0.

```c
#include <stdio.h>

int main(int argc, char* argv[]) {
    
    int sumOfNumbers = 0, inputNumber, inputCounter = 0;
    float average;
    
    printf("Inserire numero: ");
    scanf("%d", &inputNumber);
    
    while(inputNumber != 0) {
        
        inputCounter++;
        sumOfNumbers += inputNumber;
        /* == someOfNumbers = someOfNumbers + inputNumber */
        
        printf("\nInserire numero: ");
        scanf("%d", &inputNumber);
    }

    average = (sumOfNumbers * 1.0) / (inputCounter );
    
    printf("La somma totale è: %d\n", sumOfNumbers);
    printf("La media totale è: %f\n", average);
    
    return 0;
}
```

Il costrutto `do while` garantisce l'esecuzione del corpo del `while` almeno una volta:

```c
do {

    somethingFun;

} while(expression);
```

> Ovviamente anche il corpo del `while` può essere provvisto di strutture di controllo annidate con `if` o usando lo stesso `while`.

Sintassi del costrutto iterativo `for`:

```c
for(istruzioneInizializzazione; expression; istruzioneLoop) {

    corpo_for;
}
```

> Il ciclo viene regolato da una variabile di loop la quale viene inizializzata nel primo argomento del ciclo `for` (`istruzioneInizializzazione`) e l'incremento viene regolato dall'ultimo argomento del ciclo (`istruzioneLoop`). NB: la variabile di loop dev'essere dichiarata prima del costrutto iterativo `for` e non dentro il primo argomento.

Sintassi costrutto `switch case`

```c
switch(integerExpression) {

    case firstValue: 
        statementOne; 
        break;
    
    case secondValue:
        statementTwo;
        break;

    case thirdValue:
        statementThree;
        break;

    default:
        defaultStatement;
        break;
}
```

> `integerExpression` può essere anche un carattere (e non altro) e non solo `int`. Si noti inoltre come ogni label del `case` finisca con i due punti `:` e non col punto e virgola `;`. Per evitare l'esecuzione a cascata alla prima corrispondenza trovata, occorre inserire alla fine degli statements di ogni case la keyword `break`. Il `default` è opzionale, se nessuno degli altri casi viene matchato il `default` viene eseguito se è presente nel sorgente. Il `break` può essere utilizzato non solo negli `switch case` ma anche nei costrutti iterativi elementari come `while`, `do while` e `for`.

Utilizzo delle keyword `break` e `continue` nei costrutti iterativi elementari:

```c
for(index = 0; index < 10; index++) {

    scanf("%d", &randomInteger);

    if(x < 0) {

        break;
    }

    printf("%d", &randomInteger);
}
```

```c
index = 0;

while(index < 10) {

    scanf("%d", &randomInteger);

    if(x < 0) {

        continue;
    }

    printf("%d", &randomInteger);
    index++;
}
```
> Nel ciclo `for` del primo esempio se il numero acquisito è minore di zero il `break` termina ed esce dal costrutto iterativo `for` anche se si trova all'interno dell'`if`. Nel ciclo `while` del secondo esempio il `continue` fa saltare le successive istruzioni sotto di lui rimanendo nel ciclo finchè l'espressione di controllo non fallisce.

## Costanti

Dichiarando una costante viene stabilito un valore definitivo e non rimpiazzabile ad un identificatore. Nel caso in cui si provi ad assegnare un valore ad una costante dopo averla già inizializzata il compilatore darà errore. Le costanti sono utili per non avere un codice ripetitivo. La sintassi generica per definire una costante è `const typeKeyword identifier = value;`.

```c
const float pi = 3.14;
const int fixedNumber = 23;
const char serialChar = 'G';
```

## Array

Gli array sono sequenze di variabili omogenee, ovvero tutte le variabili della sequenza sono dello stesso type ed ogni elemento della sequenza è individuato da un indice. La sintassi del costruttore generale è `tipo identificatoreArray[Dimensione]`.

```c
int carPlate[7];
char codiceFiscale[16];
float coordinates[30];
```
> Le dimensioni specificate degli array sono numeri fissi e non è possibile modificarle durante l'esecuzione.

Ogni elemento dell'array è una variabile del tipo dell'array ed è possibile accedere ad essi specificandone un indice fra parentesi quadre `[]`:

```c
int someIntegers[34];
someIntegers[0]; /* primo elemento */
someIntegers[25];
someIntegers[33]; /* ultimo elemento */
```

Esempi di operazioni su array:

```c
/* assegnazione */
someIntegers[2] = 23;
someIntegers[31] = 12 % 4;
someIntegers[20] = someIntegers[20 + 6];

/* operazioni logiche */
someIntegers[4] == someIntegers[13];
someIntegers[15] > someIntegers[9];

/* operazioni aritmetiche */
someIntegers[0] = someIntegers[17] / someIntegers[16];

/* operazioni I/O */
int index;
scanf("%d", &someIntegers[index]);
printf("Valore all'indice %d = %d", index, someIntegers[index]);

```

Errore da non fare con il costruttore array:

```c
int dimension;

scanf("%d", &dimension);
float wrongArr[dimension];
```

> Questo metodo di costruzione non è standard ANSI C 89, spesso infatti si ricorre alla direttiva di precompilazione `define` per dichiarare la dimensione di un array.

**Esercizio** » Chiedere all'utente di inserire un array di interi (dimensione definita da `effectiveController`) ed un numero intero `integerFlag`. Il programma salva gli elementi inseriti in `arrOne` e copia tutti gli elementi di `arrOne` che sono maggiori di `integerFlag` in un secondo vettore `arrTwo`. La copia deve avvenire nella parte iniziale di `arrTwo` senza lasciare buchi.

```c
#include <stdio.h>

#define ARR_ELEMENTS 30

int main(int argc, char* argv[]) {

    int arrOne[ARR_ELEMENTS], arrTwo[ARR_ELEMENTS], effectiveController = 10, 
        integerFlag, indexLoop, subIndexLoop = 0;
     

    printf("Inserire l'integer flag: ");
    scanf("%d", &integerFlag);

    /* riempimento di entrambi gli array*/
    for(indexLoop = 0; indexLoop < effectiveController; indexLoop++) {

        printf("\nInserire l'elemento dell'indice %d: ", indexLoop);
        scanf("%d", &arrOne[indexLoop]);

        /* condizione di riempimento del secondo array*/
        if(arrOne[indexLoop] > integerFlag) {

            arrTwo[subIndexLoop] = arrOne[indexLoop];
            subIndexLoop++;
        }
    }

    /* stampa array */
    printf("\n[ ");

    for(indexLoop = 0; indexLoop < effectiveController; indexLoop++) {

        printf("%d  ", arrOne[indexLoop]);
    }

    printf("]\n");
    printf("\n[ ");

    for(indexLoop = 0; indexLoop < subIndexLoop; indexLoop++) {

        printf("%d  ", arrTwo[indexLoop]);
    }

    printf("]\n");



    return 0;
}
```

### Array di caratteri e stringhe

In c le stringhe sono realizzate mediante array di caratteri. La differenza fra una stringa ed un array di caratteri è il terminatore della stringa `'\0'`. Se mi viene chiesto di gestire stringhe al più `N` caratteri devo allocare un vettore con dimensione `N+1`.

```c
#define N 50

char firstAnswer[N + 1];
``` 

> Viene definito un array di `50` caratteri di tipo `char` più un `'\0'` che rappresenta la fine della stringa. NB: non esiste il tipo predefinito `string`.

Una modalità di riempimento dell'array di caratteri per creare una stringa può avvenire tramite un ciclo `for` (anche se non funziona e bugga) o tramite `scanf()`.

```c
#define N 100

char randomString[N];

/* primo metodo */
scanf("%s\n", randomString);

/* secondo metodo */
scanf("%[^\n]", randomString);

printf("%s\n", randomString);
```

> Il primo metodo acquisisce la stringa fino al primo spazio mentre mentre nel secondo metodo acquisisce fino all'inserimento del primo invio. NB: `randomString` è l'indirizzo del primo elemento `&randomString[0]`, `scanf()` quindi non ha bisogno della `&`. Entrambi delimitano automaticamente la parte significativa dal terminatore `'\0'`.

É possibile calcolare la lunghezza di una stringa con un ciclo usando la flag `'\0'`:

```c
char randomString[30];
int countChar = 0;

scanf("%[^\n]", randomString);

while(randomString[countChar] != '\0') {countChar++;}

printf("Lunghezza stringa: %d\n", countChar);

```

Un metodo più semplice è utilizzare la funzione `strlen()`, contenuta nella libreria `string`:

```c
#include <string.h> /* !! importare libreria !! */

int countChar = strlen(randomString);
```

**Esercizio** » Verificare se due stringhe coincidono per lunghezza e se coincidono per ogni elemento.

```c
#include <stdio.h>
#include <stdlib.h> /* libreria per exit() */
#include <string.h> /* libreria per strlen() */

#define C 100

int main(int argc, char* argv[]) {

    char firstString[C], secondString[C];
    int arrChecker, flag;

    printf("Inserire due stringhe: ");
    scanf("%[^\n] %[^\n]", firstString, secondString);

    /* confronto lunghezza */
    if( strlen(firstString) == strlen(secondString) ) {

        /* confronto indice per indice */
        for(arrChecker = 0; arrChecker < ((int) strlen(firstString)); arrChecker++) {

            if(firstString[arrChecker] != secondString[arrChecker]) {

                printf("Stringhe lunghe uguali ma diversi caratteri\n");
                exit(0);
            }
        }

        printf("Stringhe identiche, %d caratteri\n", (int) strlen(firstString));
    
    } else {

        printf("Stringhe diverse!\n");
    }

    return 0;
}
```

É possibile eseguire la copia del contenuto di un array ad un altro chiamando `strcpy()` con gli array come argomenti. Il primo argomento è l'array copiato, mentre il secondo argomento è l'array copiante. Per accodare le stringhe si usa `strcat()`; ha lo stesso verso degli argomenti come per copiare.

### Array multidimensionali

Si possono definire array con più di una dimensione mediante il classico costruttore array.

```c
int randomMatrix[10][12];
char matrixWords[3][20];
int triMatrix[21][15][4];
``` 

### Struct vs Array

Gli array aggregano variabili omogenee in una sequenza precisa. Le `struct` permettono di aggregare variabili eterogenee in una sola variabile ed è una sorta di "contenitore" per variabili disomogenee di tipi più semplici. Le variabili aggregate nella struct sono dette campi della struct.

Sintassi dello `struct`:

```c
struct {

    keywordTipoUno nomeCampoUno;
    keywordTipoDue nomeCampoDue;

    keywordTipoN nomeCampoN;
    
} nomeStruct;
```

## Sottoprogrammi

I sottoprogrammi venogono definiti per tipo che returnano o se non returnano alcun tipo. Le variabili locali definite in un sottoprogramma restano inglobate nel sottoprogramma a meno che non ne venga esportato il valore con una istruzione `return`. Non è violazione di standard balzare la function prototype mettendo in stack i sottoprogrammi prima del main in modo tale che il compilatore conosca già la pre-definition dei vari sottoprogrammi.

```c
double anotherSubProgram(double callerOne) {/* definizione */}
void reimbursement_calc(void) {/* definizione */}

int main(int argc, char* argv[]) {

    double numOne;

    reimbursement_calc();
    anotherSubProgram(numOne);
    
    return 0;
} 
```

## Puntatori e programmazione modulare

```c
float temp;
float *point = &temp; /* salva l'indirizzo di temp nel puntatore point */
```

> Identifica `point` come una variabile puntatore, in particolare un puntatore a `float`. Questo significa che possiamo memorizzare l'indirizzo di memoria di una variabile di tipo `float` in `point`.

Vari utilizzi dei pointers anche con i files che non ho voglia di spiegare, *let the code explains itself*:

```c
#include <stdio.h>
#include <math.h>

void separate(double valueToAnalyze, double *fracP, char *signP, int *wholeP) {

    if(valueToAnalyze < 0) {

        *signP = '-';

    } else if(valueToAnalyze == 0) {

        *signP = ' ';

    } else {

        *signP = '+';

    }

    *wholeP = floor(fabs(valueToAnalyze));
    *fracP = fabs(valueToAnalyze) - floor(fabs(valueToAnalyze));
}

void separate_value() {

    double value, frac;
    char sign;
    int whole;

    printf("Inserire un valore da analizzare => ");
    scanf("%lf", &value);

    separate(value, &frac, &sign, &whole);

    printf("Parts of %.4f\n Sign: %c\n Whole number magnitude: %d\n Fractional part: %.4f\n"
            , value, sign, whole, frac);
}

void files_read_n_write(void) {

    FILE *fWritePointer;
    FILE *fReadPointer;
    char myLine[100];

    fWritePointer = fopen("writingFile.txt", "w");
    fReadPointer = fopen("anotherFile.txt", "r");

    /* write to a file */
    fprintf(fWritePointer, "HOLA SOY DORA\n");

    /* reading from a file */
    while(!feof(fReadPointer)) {
        
        fgets(myLine, 100, fReadPointer);
        puts(myLine);
    }

    fclose(fReadPointer);
    fclose(fWritePointer);
}

int main(int argc, char* argv[]) {

        /*files_read_n_write();*/
        separate_value();


    return 0;
}
```








