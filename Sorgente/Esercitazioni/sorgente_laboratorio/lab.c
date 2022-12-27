#include <stdio.h>
#include <math.h>

#define BASE 10
#define BLOCK '#'

void triangolo_tartaglia(void) {

    int ampiezza, indexLoop;
    int triangle[BASE];
    
    do {

        printf("Inserire l'ampiezza del triangolo di Tartaglia (massimo 10) => ");
        scanf("%d", &ampiezza);

    } while( (ampiezza <= 0) || (ampiezza >= 10) );

    for(indexLoop = 0; indexLoop < BASE ; indexLoop++) {

        triangle[indexLoop] = 0;
        printf("%d ", triangle[indexLoop]);
    }
}























void troncabile_primo_dx(void) {

    int num, troncabile;
    
    do {

        printf("Inserire un valore intero positivo => ");
        scanf("%d", &num);

    } while(num <= 0);

    do {
    
        if( ((num != 2) && (num != 3) && (num != 5) && (num != 7)) ) {

            if( ((num % 2) != 0) && ((num % 3) != 0) && ((num % 5) != 0) && ((num % 7) != 0) ) {

                troncabile = 1;
            } else {
                troncabile = 0;
            }

        } else {

            troncabile = 1;
        }

        num = num / BASE;

    } while(num > 0);

    printf("%d\n", troncabile);
}

void super_mario(void) {

    int heightPiramid, heightPiramidController, indexLoop, mainIndexLoop, counterBlock = 1;

    do {
        
        printf("Inserire un valore intero non superiore a 16 => ");
        scanf("%d", &heightPiramid);
    
    } while(heightPiramid < 0 || heightPiramid > 16);

    heightPiramidController = heightPiramid;

    /* ciclo for generale */
    for(mainIndexLoop = 0; mainIndexLoop < heightPiramid; heightPiramidController--, counterBlock++, mainIndexLoop++) {

        /* ciclo for per spazi iniziali */
        for(indexLoop = 0; indexLoop < heightPiramidController -1; indexLoop++) {

            printf(" ");
        }

        /* ciclo for per i primi blocchi della piramide */
        for(indexLoop = 0; indexLoop < counterBlock; indexLoop++) {

            printf("%c", BLOCK);
        }

        /* spazio intermedio */
        printf("  ");

        /* ciclo for per i secondi blocchi della piramide */
        for(indexLoop = 0; indexLoop < counterBlock; indexLoop++) {

            printf("%c", BLOCK);
        }

        /* ciclo for per spazi finali */
        for(indexLoop = 0; indexLoop < heightPiramidController -1; indexLoop++) {

            printf(" ");
        }

        printf("\n");
    }   

}

void padding_numbers(void) {

    /* per visualizzazioni su 8 byte usare long */
    int num, k, indexLoop;

    /* check for the correct values */
    do {

        printf("Inserire due numeri interi strettamente positivi => ");
        scanf("%d%d", &num, &k);

    } while( (num < 0) || (k < 0) );

    /* check visualizzazione del numero su k cifre */
    if( num <= (pow(10, k) -1) ) {

        printf("Numero visualizzabile\n");

    } else {
        
        printf("Numero non visualizzabile\n");
    }
    
    /* for loop per il conteggio zeri */
    for(indexLoop = 0; indexLoop < k; indexLoop++, k--) {

        if( num >= (pow(10, k) -1) ) {

            break;
        }
    }

    /* ciclo per stampa dei zeri */
    while( (indexLoop - 1) > 0 ) {

        printf("0");
        indexLoop--;
    }

    printf("%d\n", num);
    
}

int main(int argc, char* argv[]) {

    /*padding_numbers();*/
    /*super_mario();*/
    /*troncabile_primo_dx();*/
    triangolo_tartaglia();

    return 0;
}