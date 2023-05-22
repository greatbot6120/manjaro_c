/*
    Scrivere un programma che acquisisce una sequenza di al più 100 valori
    interi e un intero strettamente positivo k. L'acquisizione termina quando
    l'utente inserisce un numero negativo o nullo, oppure quando vengono
    acquisiti 100 valori. Il programma visualizza 1 se la sequenza contiene
    almeno una coppia di valori tali che la loro somma sia k, 0 altrimenti.
    Si sviluppi un sottoprogramma findSum() che ricevuto in ingresso k, l'array
    contenente i dati e qualsiasi altro parametro ritenuto strettamente
    necessario, restituisce 1 o 0 nel caso trovi i due valori la cui somma è k.
 */


#include <stdio.h>
#define MAX_NUMS 100

int findSum(const int *p_nums, const int k, const int limit) {
    
    int sum_status = 0, index, subIndex, tempSum;

    for(index = 0; index < limit; index++) {

        for(subIndex = index + 1; subIndex < limit; subIndex++) {

            tempSum = *(p_nums + index) + *(p_nums + subIndex);

            if(tempSum == k) {

                return(sum_status = 1);
            }
        }
    }

    return (sum_status);
}

void sommaK(void) {

    int nums[MAX_NUMS], k = 6, indexLoop, sumStatus;

    for(indexLoop = 0; indexLoop < MAX_NUMS; indexLoop++) {

        printf("Inserire elemento N. %d >> ", indexLoop);
        scanf("%d", &nums[indexLoop] );

        if ( (nums[indexLoop] < 0) || (nums[indexLoop] == 0) ) {
            
            break;
        }
    }

    sumStatus = findSum(nums, k, indexLoop);
    printf("%d\n", sumStatus);
}

int main(int argc, char* argv[]){

    sommaK();
    return (0);
}