/*
    Scrivere un programma che mostri a video il traingolo di Tartaglia di
    dimensione massimo 10. Eseguire un controllo di validità sulla dimensione
    richiesta all'utente e nel caso richiederla. Esempio di dimensione 5:

    1
    1 2 1
    1 3 3 1
    1 4 6 4 1
 */

#include <stdio.h>
#define MAX_DIM 10

void tartaglia(void) {

    int dimension, triangle[MAX_DIM][MAX_DIM] = { {1}, {1, 1} };

    do {

        printf("Digitare la dimensione del triangolo di Tartaglia >> ");
        scanf("%d", &dimension);

    } while(dimension <= 0 || dimension > 10);

    for() {

        printf("1");
        printf("")
    }




}

int main(int argc, char* argv[]) {

    tartaglia();
    return (0);
}