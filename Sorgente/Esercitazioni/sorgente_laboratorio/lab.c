#include <stdio.h>
#include <math.h>
#include <string.h>

#define LIMIT 50
#define BASE 15
#define BLOCK '#'

int extract_value_sum(const int *arraySum, int *kPointer, int *indexLooP) {

    int exit_sum_status = 0, mainIndex, subIndex, next;

    for(mainIndex = 0; mainIndex < *indexLooP; mainIndex++) {

        for(next = 1; mainIndex < *indexLooP; next++) {

            if((arraySum[mainIndex] + arraySum[mainIndex + next]) == *kPointer) {

                exit_sum_status = 1;
                break;

            }
        } 
    }

    return (exit_sum_status);
}

void find_sum(void) {

    int container[LIMIT], indexLoop, k;

    printf("Inserire l'elemento k => ");
    scanf("%d", &k);

    for(indexLoop = 0; indexLoop < LIMIT; indexLoop++) {

        printf("Inserire elemento N. %d => ", indexLoop + 1);
        scanf("%d", &container[indexLoop]);

        if(container[indexLoop] < 0 || container[indexLoop] == 0) {
            
            indexLoop--;
            break;
        }
    }

    printf("%d\n", extract_value_sum(container, &k, &indexLoop));
} 

void string_rotation(void) {

    char firstSequence[LIMIT], secondSequence[LIMIT];
    int slider, indexLoop, subIndexLoop, length;

    printf("Inserire una stringa di massimo 50 caratteri => ");
    scanf("%s", firstSequence);
    
    length = strlen(firstSequence);

    do {

        printf("Inserire lo slider (dev'essere minore della lunghezza della stringa) => ");
        scanf("%d", &slider);

    } while (slider > length);

    for(indexLoop =  length - slider , subIndexLoop = 0; indexLoop < length; indexLoop++, subIndexLoop++) {

            secondSequence[subIndexLoop] = firstSequence[indexLoop];
    }

    for(subIndexLoop = 0; subIndexLoop < length - slider; subIndexLoop++) {
        
        secondSequence[subIndexLoop + slider] = firstSequence[subIndexLoop];
    }
    
    for(subIndexLoop = 0; subIndexLoop < length; subIndexLoop++) {

        printf("%c", secondSequence[subIndexLoop]);
    }

    printf("\n");
}

void triangolo_tartaglia(void) {

    int triangle[BASE][BASE], indexLoop, subIndexLoop, amp;

    for(indexLoop = 0; indexLoop < BASE; indexLoop++) {

        for(subIndexLoop = 0; subIndexLoop < BASE; subIndexLoop++) {

            if( (indexLoop == subIndexLoop) || (subIndexLoop == 0) ) {
                
                triangle[indexLoop][subIndexLoop] = 1;

            } else {

                triangle[indexLoop][subIndexLoop] = 0;
            }
        }
    }

    for(indexLoop = 1; indexLoop < BASE; indexLoop++) {

        for(subIndexLoop = 1; subIndexLoop < BASE; subIndexLoop++) {

                triangle[indexLoop + 1][subIndexLoop] = triangle[indexLoop][subIndexLoop] + triangle[indexLoop][subIndexLoop - 1];
        }
    }

    do {

        printf("Scegliere l'ampiezza del triangolo di Tartaglia (massimo 10) => ");
        scanf("%d", &amp);

    } while(amp < 0 || amp > BASE);

    for(indexLoop = 0; indexLoop < amp; indexLoop++) {
        
        for(subIndexLoop = 0; subIndexLoop < amp; subIndexLoop++) {

            if(triangle[indexLoop][subIndexLoop] != 0) {

            printf("[%d] ", triangle[indexLoop][subIndexLoop]);
            
            }
        }

        printf("\n");
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

        printf("Inserire due numeri interi strettamente positivi >> ");
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
    /*triangolo_tartaglia();*/
    /*string_rotation();*/
    /*find_sum();*/
    
    return 0;
}
