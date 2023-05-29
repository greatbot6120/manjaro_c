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


    for(indexLoop = 0; indexLoop < MAX_ARR - 1; indexLoop++) {

        for(subIndexLoop = 0; subIndexLoop < MAX_ARR; subIndexLoop++) {

            if() {

            }
        }
    }



}




int main(int argc, char* argv[]) {

    int a1[MAX_ARR] = {51, 83, 99, 11, 15, 22, 52, 1, 92, 58, 73, 1, 57, 42, 94, 24, 68, 61, 70, 67};
    int a2[MAX_ARR] = {35, 29, 61, 57, 99, 53, 63, 78, 36, 4, 43, 96, 57, 26, 58, 29, 33, 15, 36, 62};
    int a3[MAX_ARR * 2];

    mixArr(a1, a2, a3);
    
    return (0);
}