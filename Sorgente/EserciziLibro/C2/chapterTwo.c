#include <stdio.h>

void reimbursement_calc(void) {

    float startKm, endKm;

    printf("Enter beginning odometer reading => ");
    scanf("%f", &startKm);

    printf("Enter ending odometer reading => ");
    scanf("%f", &endKm);

    printf("You traveled %.2f kilometers. A 0.35 euros per kilometer, your reimbursement is %.2f.\n", endKm - startKm, (endKm - startKm) * 0.35);
}

int main(int argc, char* argv[]) {

    reimbursement_calc();

    return 0;
} 