# C

#### Input and printing using local variables 

```C
#include <stdio.h>

int main() {
	int myAge;
	int anotherAge; //local variable
	printf("Enter your age: ");
	scanf("%d", &myAge); //input from user
	printf("Enter another age: ");
	scanf("%d", &anotherAge);
	printf("Your age plus the other is %d years old\n", myAge + anotherAge);
	return 0;
}
```

#### Types of variables in C

```C
int catValue; //global variable outside the function or block, accessible for all functions

void aSimpleFunction() {
	int runningCat; //local variable
	static int anotherCatValue; //static varibale will retain its value between multiple function calls
	auto int autoVarCat; /* all variables that are declared inside the block, are automatic variables 
						  * by default. We can explicity declare an automatic variable using auto keyword
						  */
}
```

> *__External__ variable:*

```C

```