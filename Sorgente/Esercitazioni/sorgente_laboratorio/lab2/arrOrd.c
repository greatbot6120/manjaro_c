/*
    Scrivere un sottoprogramma mixArr() in C che, ricevuti come parametri tre array e
    qualsiasi altro parametro ritenuto strettamente necessario, salva nel terzo
    array una copia dei valori contenuti nel primo e nel secondo array
    ordinandoli in ordine crescente e senza ripetizioni e restituisce il numero
    di elementi effettivamente scritti nel terzo array. E' necessario tener
    conto dei seguenti aspetti:

        - il sottoprogramma può modificare i dati contenuti negli array di
          partenza;

        - si assuma che il terzo array abbia abbastanza spazio per memorizzare
          la sequenza risultante;

    Nello sviluppo della soluzione realizzare un sottoprogramma sortArr() che
    ricevuti in ingresso un array, un intero updown e qualsiasi altro parametro
    ritenuto strettamente necessario, ordina il contenuto dell'array in senso
    crescente se updown vale 1, in senso decrescente se vale -1. Nel caso 
    updown contenga un valore diverso il sottoprogramma non effettua alcuna 
    modifica. Sviluppare infine un programma che chiede all'utente i dati per
    popolare due array da 20 elementi, invoca il sottoprogramma sopra definito
    e visualizza il risultato (la visualizzazione non viene fatta nel
    sottoprogramma mixArr).  
 */

#include <stdio.h>
#define MAX_ARR 20

void mixArr(int *pA1, int *pA2, int *pA3) {

    int indexLoop, subIndexLoop, exclude, subExclude, tempMin;

    /* escludiamo i valori ripetuti mettendo un '-' davanti */
    for(indexLoop = 0; indexLoop < MAX_ARR - 1; indexLoop++) {

        for(subIndexLoop = indexLoop + 1; subIndexLoop < MAX_ARR; subIndexLoop++) {

            if( pA1[indexLoop] ==  pA1[subIndexLoop] ) {

                pA1[subIndexLoop] = - pA1[subIndexLoop];
            }

            if( pA2[indexLoop] ==  pA2[subIndexLoop] ) {

                pA2[subIndexLoop] = - pA2[subIndexLoop];
            }
        }
    }

    /* escludiamo i valori uguali fra a1 e a2 sempre mettendo un '-' davantii */
    for(indexLoop = 0; indexLoop < MAX_ARR; indexLoop++) {

        for(subIndexLoop = 0; subIndexLoop < MAX_ARR; subIndexLoop++) {
            
            if( (pA1[indexLoop] == pA2[subIndexLoop]) && ((pA1[indexLoop] >= 0) && (pA2[subIndexLoop] >= 0)) ) {

                pA2[subIndexLoop] = - pA2[subIndexLoop];
            }
        }
    }

    printf("\nMODIFIED A1 >> [ ");

    for(indexLoop = 0; indexLoop < MAX_ARR; indexLoop++) {

        printf("%d ", *(pA1 + indexLoop));
    }

    printf("]\nMODIFIED A2 >> [ ");

    for(indexLoop = 0; indexLoop < MAX_ARR; indexLoop++) {

        printf("%d ", *(pA2 + indexLoop));
    }

    printf("]\n");

    /* copia a1 in a3 escludendo i valori segnati in precedenza */
    for(indexLoop = 0, exclude = 0; indexLoop < MAX_ARR; indexLoop++) {

        if(pA1[indexLoop] >= 0) {

            pA3[indexLoop - exclude] = pA1[indexLoop];
        
        } else {

            exclude++; /* incremento per shiftare a sx l'indice di a3 */
        }
    }

    printf("\nCOPIA A1 IN A3 >> [ ");

    for(indexLoop = 0; indexLoop < MAX_ARR - exclude; indexLoop++) {

        printf("%d ", *(pA3 + indexLoop));
    }

    printf("]\n");

    /* 
        indice che parte da dove siamo rimasti prima in a3, includendo lo shift
        di posizione di a3 per non generare buchi/sostituzioni.

        subIndexLoop usato per a2 copiante che ha un incremento lineare.

        subExclude per riportarci i shift generati da a2.

        La condizione del for rispetta la dimensione globale di a3 meno le
        esclusioni che ci siamo portati da a1 e rispetta in contemporanea
        l'indice di a2.  
     */
    for(indexLoop = MAX_ARR - exclude, subIndexLoop = 0, subExclude = 0; (indexLoop < (MAX_ARR * 2) - exclude) && (subIndexLoop < MAX_ARR); indexLoop++, subIndexLoop++) {

        if(pA2[subIndexLoop] >= 0) {

            pA3[indexLoop - subExclude] = pA2[subIndexLoop];

        } else {

            subExclude++;
        }
    }

    printf("\nCOPIA A1 E A2 IN A3 >> [ ");
    
    /* sottraiamo alla dimensione iniziale  */
    for(indexLoop = 0; indexLoop < (MAX_ARR * 2) - exclude - subExclude; indexLoop++) {

        printf("%d ", *(pA3 + indexLoop));
    }

    printf("]\n");

    /* sorting array a3 */
    for(indexLoop = 0; indexLoop < (MAX_ARR * 2) - exclude - subExclude - 1; indexLoop++ ) {

        for(subIndexLoop = indexLoop + 1; subIndexLoop < (MAX_ARR * 2) - exclude - subExclude; subIndexLoop++) {

            if(pA3[indexLoop] > pA3[subIndexLoop]) {

                tempMin = pA3[subIndexLoop];
                pA3[subIndexLoop] = pA3[indexLoop];
                pA3[indexLoop] = tempMin;
            }
        }
    }

    printf("\nSORTED A3 >> [ ");
    
    /* sottraiamo alla dimensione iniziale  */
    for(indexLoop = 0; indexLoop < (MAX_ARR * 2) - exclude - subExclude; indexLoop++) {

        printf("%d ", *(pA3 + indexLoop));
    }

    printf("]\n\n");
}

int main(int argc, char* argv[]) {

    int a1[MAX_ARR] = {51, 83, 99, 11, 15, 22, 52, 1, 92, 58, 73, 1, 57, 42, 94, 24, 68, 61, 70, 67};
    int a2[MAX_ARR] = {35, 29, 61, 57, 99, 53, 63, 78, 36, 4, 43, 96, 57, 26, 58, 29, 33, 15, 36, 62};
    int a3[MAX_ARR * 2];

    mixArr(a1, a2, a3);
    
    return (0);
}