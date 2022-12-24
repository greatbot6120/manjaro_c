#include <stdio.h>

#define TEACHER_DISCOUNT_OVER 0.12
#define TEACHER_DISCOUNT_UNDER 0.10

int main(int argc, char* argv[]) {

    float total;
    char teacher;

    printf("Inserire il totale dell'acquisto => ");
    scanf("%f", &total);
    
    printf("Sei un maestro di musica? (Y/n) => ");
    scanf(" %c", &teacher);

    if(teacher == 'y') {

        if(total > 100) {

            printf("Total purchases\t\t €%.2f\nTeacher's discount (12%%)\t\t -%.2f\nDiscounted total\t\t €%.2f\nSales tax (5%%)\t\t +%.2f\nTotal\t\t €%.2f\n", 
                    total, total*TEACHER_DISCOUNT_OVER, total - total*TEACHER_DISCOUNT_OVER, (total - total*TEACHER_DISCOUNT_OVER)*0.05, (total - total*TEACHER_DISCOUNT_OVER) + ((total - total*TEACHER_DISCOUNT_OVER)*0.05));
        } else {

            printf("Total purchases\t\t €%.2f\nTeacher's discount (10%%)\t\t -%.2f\nDiscounted total\t\t €%.2f\nSales tax (5%%)\t\t +%.2f\nTotal\t\t €%.2f\n", 
                    total, total*TEACHER_DISCOUNT_UNDER, total - total*TEACHER_DISCOUNT_UNDER, (total - total*TEACHER_DISCOUNT_UNDER)*0.05, (total - total*TEACHER_DISCOUNT_UNDER) + ((total - total*TEACHER_DISCOUNT_UNDER)*0.05));
        }

    } else {

        printf("Total purchases\t\t %.2f\nSales tax (5%%)\t\t %.2f\nTotal\t\t €%.2f\n", total, total*0.05, total + total*0.05);
    }


    return 0;
}