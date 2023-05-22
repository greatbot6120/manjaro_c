/*
 |
 |   Scrivere un programma che acquisisce un valore intero strettamente positivo,
 |   e finchè non è tale lo richiede. Il programma visualizza 1 se il numero
 |   stesso e tutti i numeri che si ottengono eliminando uno alla volta la cifra
 |   meno significativa del numero analizzato al passo precedente, sono numeri
 |   primi. Esempio: 719, eliminando un numero alla volta sono tutti primi, 719
 |   >> 71 >> 7. Dopo il valore visualizzato mettere un 'a capo'.
 |
 */

 #include <stdio.h>
 #include <stdlib.h>
 #define BASE 10

void troncabile(void) {

    int num, indexLoop, is_troncabile = 1;

    do {

        printf("Inserire un numero intero strettamente positivo >> ");
        scanf("%d", &num);

    } while(num <= 0);

    while(num > 0) {
        
        /*
        | 
        |    controllo i moduli da n - 1, escludendo i casi divisibile per se
        |    stesso e per 1 che sono già verificati per ogni valore.
        |
        */
        for(indexLoop = num - 1; indexLoop >= 2; indexLoop--) {

            if( (num % indexLoop) == 0 ) {

                printf("0\n");
                exit( EXIT_SUCCESS );
            }
        }

        num /= BASE;
    }

    printf("1\n");
}

int main(int argc, char* argv[]) {

    troncabile();
    
    return (0);
 }