#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 100

int main(int argc, char* argv[]) {

	char firstString[C], secondString[C];
	int arrChecker, flag;

	printf("Inserire due stringhe: ");
	scanf("%[^\n] %[^\n]", firstString, secondString);

	if( strlen(firstString) == strlen(secondString) ) {

		for(arrChecker = 0; arrChecker < ((int) strlen(firstString)); arrChecker++) {

			if(firstString[arrChecker] != secondString[arrChecker]) {

				printf("Stringhe lunghe uguali ma diversi caratteri\n");
				exit(0);
			}
		}

		printf("Stringhe identiche, %d caratteri\n", (int) strlen(firstString));
	
	} else {

		printf("Stringhe diverse!\n");
	}

	return 0;
}