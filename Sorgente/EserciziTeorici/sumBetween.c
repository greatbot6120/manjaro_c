/*
    Scrivere una funzione ricorsiva che calcola la somma di tutti gli interi
    compresi tra due argomenti passati come parametri.
*/

#include <stdio.h>

int sumBetween(int a, int b) {

    if(a == b) {

        return (a);

    } else {

        return (a + sumBetween(a + 1, b));
    }
}

void wrapper(void) {

    printf("%d\n", sumBetween(3, 12));
}

int main() {

    wrapper();

    return(0);
}