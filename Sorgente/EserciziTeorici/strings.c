#include <stdio.h>

#define N 30

int main(int argc, char* argv[]) {

	char randomString[N];
	int countChar = 0;

	scanf("%[^\n]", randomString);

	while(randomString[countChar] != '\0') {countChar++;}
	
	printf("Lunghezza stringa: %d\n", countChar);

	return 0;
}