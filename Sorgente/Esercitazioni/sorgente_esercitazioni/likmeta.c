#include <stdio.h>
#include <math.h>

void rootCalc(float a, float b, float c) {

    float delta = pow(b, 2) - (4*(a * c));

    if(delta == 0) {

        printf("Abbiamo una sola radice: x1 = %f\n", (-b / (2*a)));
    
    } else if(delta > 0) {

        printf("Abbiamo due radici: x1 = %.2f\t x2 = %.2f\n", (-b + sqrt(delta)) / (2*a), (-b - sqrt(delta)) / (2*a));

    } else {

        printf("Il polinomio non ha radici.\n");
    }
}

void acquisitionRootCalc(void) {

    float a, b, c;

    printf("Inserire tre radici a,b,c => ");
    scanf("%f%f%f", &a, &b, &c);

    rootCalc(a, b, c);
}

int main(int argc, char* argv[]) {

    acquisitionRootCalc();

    return 0;
}

