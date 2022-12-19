/*Chiedere all’utente di inserire un array di interi (di
dimensione n1 definita precedentemente) e quindi un
numero intero n. Il programma quindi:
• salva gli elementi inseriti in un vettore v1.
• Copia tutti gli elementi di v1 che sono maggiori di n in
un secondo vettore v2.
• La copia deve avvenire nella parte iniziale di v2, senza
lasciare buchi.
*/

#include <stdio.h>

#define ARR_ELEMENTS 30

int main(int argc, char* argv[]) {

	int arrOne[ARR_ELEMENTS], arrTwo[ARR_ELEMENTS], effectiveController = 10, 
		integerFlag, indexLoop, subIndexLoop = 0;
	 

	printf("Inserire l'integer flag: ");
	scanf("%d", &integerFlag);

	for(indexLoop = 0; indexLoop < effectiveController; indexLoop++) {

		printf("\nInserire l'elemento dell'indice %d: ", indexLoop);
		scanf("%d", &arrOne[indexLoop]);

		if(arrOne[indexLoop] > integerFlag) {

			arrTwo[subIndexLoop] = arrOne[indexLoop];
			subIndexLoop++;
		}
	}

	printf("\n[ ");

	for(indexLoop = 0; indexLoop < effectiveController; indexLoop++) {

		printf("%d  ", arrOne[indexLoop]);
	}

	printf("]\n");
	printf("\n[ ");

	for(indexLoop = 0; indexLoop < subIndexLoop; indexLoop++) {

		printf("%d  ", arrTwo[indexLoop]);
	}

	printf("]\n");



	return 0;
}