/*  
    Si vuole rappresentare a video un valore naturale num utilizzando un numero 
    a scelta di cifre k inserendo 0 nelle posizioni più significative, fino a 
    raggiungere la dimensione desiderata. Per esempio, volendo rappresentare 842
    su 5 cifre, si ottiene 00842. Scrivere un programma che acquisisce due 
    valori interi entrambi strettamente positivi (e finchè non è così richiede 
    il valore che non rispetta il vincolo) num e k, quindi rappresenta num su k 
    cifre. Se k è minore del numero di cifre presenti in num, il programma
    visualizza il valore num come è. Dopo il valore visualizzato, mettere un
    'a capo'.
 */ 

#include <stdio.h>
#include <math.h>

void padding(void) {

    int num, k;

    /* check valori corretti */
    do {

        printf("Inserire num e k positivi >> ");
        scanf("%d%d", &num, &k);

    } while( (num < 0) || (k < 0) );

    /*  
        utilizzo pow() per delimitarmi un intervallo di valori in cui num cade.
        Utilizzando questa composizione di condizioni mi assicuro di non
        aggiungere uno zero in più.
     */
    while( ((pow(10, k) - 1) >= num) && ((pow(10, k - 1) - 1) >= num)) {

        printf("0");
        k--;
    }

    printf("%d\n", num);
    
}

int main(int argc, char* argv[]) {

    padding();

    return (0);
 }