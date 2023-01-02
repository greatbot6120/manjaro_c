#include <stdio.h>
#include <string.h>

#define DIM_ONE 5
#define DIM_TWO 2

int main(int argc, char* argv[]) {

    int firstArr[DIM_ONE][DIM_ONE] = {{3, 5, 54, 93, 23}, {4, 9, 65, 89, 77}, {3, 5, 912, 81, 97}, {4, 9, 25, 78, 79}, {932, 452, 4398, 876, 5433}};
    int secondArr[DIM_TWO][DIM_TWO] = { {3, 5}, {4, 9} };
    int rowSlider, colSlider, indexLoop, subIndexLoop, matchStatus, equalityCounter = 0;


    for(rowSlider = 0; rowSlider < DIM_ONE - 1; rowSlider++) {

        for(colSlider = 0; colSlider < DIM_ONE - 1; colSlider++) {

            for(indexLoop = 0, matchStatus = 0; indexLoop < DIM_TWO; indexLoop++) {

                for(subIndexLoop = 0; subIndexLoop < DIM_TWO; subIndexLoop++) {

                    if(secondArr[indexLoop][subIndexLoop] != firstArr[indexLoop + rowSlider][subIndexLoop + colSlider]) {

                        subIndexLoop = DIM_TWO;
                        indexLoop = DIM_TWO;

                    } else {

                        matchStatus++;

                        if(matchStatus == 4) {

                            equalityCounter++;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

    /*printf("**FIRST MATRIX**\n");
    
    for(indexLoop = 0; indexLoop < DIM_ONE; indexLoop++) {

        for(subIndexLoop = 0; subIndexLoop < DIM_ONE; subIndexLoop++) {

            printf("Enter element [%d][%d] => ", indexLoop, subIndexLoop);
            scanf("%d", &firstArr[indexLoop][subIndexLoop]);
        }
    }

    printf("**SECOND MATRIX**\n");

    for(indexLoop = 0; indexLoop < DIM_TWO; indexLoop++) {

        for(subIndexLoop = 0; subIndexLoop < DIM_TWO; subIndexLoop++) {

            printf("Enter element [%d][%d] => ", indexLoop, subIndexLoop);
            scanf("%d", &secondArr[indexLoop][subIndexLoop]);
        }
    }*/