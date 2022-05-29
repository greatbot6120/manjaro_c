//First code in C
#include <stdio.h>

int outsideGlobalVariable;

int main() {
	int myAge;
	int anotherAge;
	printf("Enter your age: ");
	scanf("%d", &myAge); //input from user
	printf("Enter another age: ");
	scanf("%d", &anotherAge);
	printf("Your age plus the other is %d years old\n", myAge + anotherAge);
	printf("Before change: %d \n", outsideGlobalVariable);
	outsideGlobalVariable = 200;
	printf("After change: %d \n", outsideGlobalVariable);
	return 0;
}