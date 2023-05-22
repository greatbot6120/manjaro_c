/*
 |
 |   Scrivere un programma che mostri a video il traingolo di Tartaglia di
 |   dimensione massimo 10. Eseguire un controllo di validità sulla dimensione
 |   richiesta all'utente e nel caso richiederla. Esempio di dimensione 5:
 |
 |   1
 |   1 1
 |   1 2 1
 |   1 3 3 1
 |   1 4 6 4 1
 |
 */

#include <stdio.h>
#define MAX_DIM 30

void tartaglia(void) {

    int dimension,indexLoop, subIndexLoop, tempSum, triangle[MAX_DIM][MAX_DIM];

    do {

        printf("Digitare la dimensione del triangolo di Tartaglia (1 - 10) >> ");
        scanf("%d", &dimension);

    } while(dimension <= 0 || dimension > MAX_DIM);

    /* mapping degli 1 lungo la diagonale e riempio il resto con degli 0 */
    for(indexLoop = 0; indexLoop < MAX_DIM; indexLoop++) {
        
        for(subIndexLoop = 0; subIndexLoop < MAX_DIM; subIndexLoop++) {
            
            /* check lungo la diagonale e nel lato con indice zero della colonna */
            if( (indexLoop == subIndexLoop) || (subIndexLoop == 0) ) {

                triangle[indexLoop][subIndexLoop] = 1;
            
            } else {

                triangle[indexLoop][subIndexLoop] = 0;
            }
        }
    }

    /*
     | 
     |   ciclo assegnazione valori del traingolo di Tartaglia:
     |   se il valore in triangle[x][y] corrisponde ad 1 si passa al prossimo
     |   indice evitando di "inquinare" i valori messi in precedenza.
     |
     */
    for(indexLoop = 2; indexLoop < MAX_DIM; indexLoop++) {

        for(subIndexLoop = 1; subIndexLoop < MAX_DIM; subIndexLoop++) {

            if(triangle[indexLoop][subIndexLoop] == 1) {

                continue;

            } else {

                tempSum = triangle[indexLoop - 1][subIndexLoop] + triangle[indexLoop - 1][subIndexLoop - 1];
                triangle[indexLoop][subIndexLoop] = tempSum;
            }
        }
    }

    /* stampa custom dei valori */
    for(indexLoop = 0; indexLoop < dimension; indexLoop++) {
        
        for(subIndexLoop = 0; subIndexLoop < MAX_DIM; subIndexLoop++) {

            printf("%d ", triangle[indexLoop][subIndexLoop]);
            
            /*
             | 
             |   condizione necessaria per non stampare i valori non interessati
             |   nel triangolo di Tartaglia
             |
             */
            if(indexLoop == subIndexLoop) {

                subIndexLoop = MAX_DIM;
            }
        }

        printf("\n");
    }
}

int main(int argc, char* argv[]) {

    tartaglia();

    return (0);
}