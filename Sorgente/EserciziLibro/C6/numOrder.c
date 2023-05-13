#include <stdio.h>

void calcSum(int firstValue, int secondValue, int *sumP) {

    *sumP = firstValue + secondValue;
}


int main(int argc, char* argv[]) {

    int a, b, sum;

    printf("Type two numbers separated by a blank: ");
    scanf("%d%d", &a, &b);

    calcSum(a, b, &sum);

    printf("Sum of %d and %d is %d\n", a, b, sum);

    return 0;
}
