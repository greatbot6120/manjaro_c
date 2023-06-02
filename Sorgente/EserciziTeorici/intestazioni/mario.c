#include <stdio.h>
#define BLOCK '#'

void superMario(const int height) {

    int spacer, mainIndexLoop, indexLoop, blockCounter = 1;

    for(mainIndexLoop = 0; mainIndexLoop < height; blockCounter++, mainIndexLoop++) {
            
            /* spazi iniziali */
            for(spacer = 0; spacer < height - mainIndexLoop; spacer++) {

                printf(" ");
            }

            /* print blocchi sx */
            for(indexLoop = 0; indexLoop < blockCounter; indexLoop++) {

                printf("%c", BLOCK);
            }

            /* spazio di 2 */
            for(spacer = 0; spacer < 2; spacer++) {

                printf(" ");
            }

            /* print blocchi dx */
            for(indexLoop = 0; indexLoop < blockCounter; indexLoop++) {
            
                printf("%c", BLOCK);
            }

            /* spazi finali */
            for(spacer = 0; spacer < height - mainIndexLoop; spacer++) {
            
                printf(" ");
            }

            printf("\n");
        }
    }
