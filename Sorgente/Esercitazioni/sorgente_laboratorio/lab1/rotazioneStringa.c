/*
    Scrivere un programma che acquisisce una stringa seq_one di massimo 50 char
    ed un numero intero num. Il valore num dev'essere minore della lunghezza
    della stringa e lo richiede finchè non c'è un valore corretto. In seguito
    si crei una seconda stringa seq_two che contiene la rotazione verso destra
    di seq_one di num posizioni e la visualizza. La nuova stringa va creata, non
    è sufficiente visualizzare il risultato. Esempio:
  
    seq_one: alfabeto   num: 2
  
    seq_two: toalfabe
 */

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 50

void rotazioneStringa(void) {

    int num, len, indexLoop, slicer;
    char seq_one[MAX_LENGTH + 1], seq_two[MAX_LENGTH + 1];

    printf("Inserire una stringa non maggiore di 50 caratteri e un numero separati da uno spazio >> ");
    scanf("%s%d", seq_one, &num);

    len = strlen(seq_one);
    
    if(num > len) {

        do {

            printf("Numero maggiore della lunghezza della stringa, digitare numero valido >> ");
            scanf("%d", &num);

        } while(num > len);
    }

    /* copia della sezione finale */
    for(indexLoop = 0, slicer = len - num; indexLoop < len - 1; indexLoop++, slicer++) {
        
        seq_two[indexLoop] = seq_one[slicer];
    }

    /* copia della parte iniziale */
    for(indexLoop = 0, slicer = num; indexLoop < len - num; indexLoop++, slicer++) {

        seq_two[slicer] = seq_one[indexLoop];
    }

    printf("%s\n", seq_two);
}

int main(int argc, char* argv[]) {

    rotazioneStringa();

    return (0);
}