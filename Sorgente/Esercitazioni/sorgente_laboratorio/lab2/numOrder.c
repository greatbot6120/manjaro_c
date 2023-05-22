/*
    Scrivere un programma che acquisisce una sequenza di al più 20 valori
    interi, chiedendo all'utente inizialmente quanti valori vorrà fornire, num.
    Il programma acquisisce num valori e memorizza in una opportuna struttura
    dati la sequenza di valori i cui elementi sono strettamente crescenti,
    trascurando i valori che risultano non essere ordinati. Al termine
    dell'acquisizione il programma visualizza la lunghezza della sequenza,
    seguita, su una nuova riga, dalla sequenza stessa. L'utente inserirà
    sempre un numeri di valori coerente con la richiesta. Avvalersi dei
    sottoprogrammi fillArrOrd() e viewArr(). Esempio:

    input:
    
    6
    1 1 6 2 5 7

    output:

    3
    1 6 7
 */


#include <stdio.h>
#define SIZE_ARR 20

void viewArr(const int* arr_view, int indexLoop, const int subIndexLoop) {

    printf("%d\n", subIndexLoop);

    for(indexLoop = 0; indexLoop < subIndexLoop; indexLoop++) {

        printf("%d ", *(arr_view + indexLoop) );
    }

    printf("\n");
}

void fillArrOrd(int* p_arr, const int given) {

    int second_arr[SIZE_ARR], indexLoop, subIndexLoop;

    for(indexLoop = 0; indexLoop < given; indexLoop++) {
        
        printf("Inserire valore N.%d >> ", indexLoop);
        scanf("%d", p_arr + indexLoop );
    }

    second_arr[0] = *p_arr;

    for(indexLoop = 1, subIndexLoop = 1; indexLoop < given; indexLoop++) {

        if( *(p_arr + indexLoop) > *(p_arr + indexLoop - 1) ) {

            second_arr[subIndexLoop] = *(p_arr + indexLoop);
            subIndexLoop++;
        }
    }

    viewArr(second_arr, indexLoop, subIndexLoop);
}

void numOrder(void) {

    int numsArr[SIZE_ARR], given;

    do {

        printf("Digitare il numero di elementi che si desidera inserire >> ");
        scanf("%d", &given);

    } while(given < 0);

    fillArrOrd(numsArr, given);
}

int main(int argc, char* argv[]) {

    numOrder();

    return(0);;
}