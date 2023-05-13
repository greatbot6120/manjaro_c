/* 
    ricreare una piramide come nei giochi di Super Mario con il carattere '#':
    
       #  #
      ##  ##
     ###  ###
    ####  ####

    Lo spazio fra le piramidi è costituito da 2 spazi, indipendentemente
    dall'altezza delle piramidi. Alla fine delle piramidi non ci devono essere
    spazi. L'utente inserisce l'altezza delle piramidi, che dev'essere un valore
    strettamente positivo e non superiore a 16. Ripetere la richiesta nel caso
    i valori non siano corretti.    
 */
 
#include <stdio.h>
#define BLOCK '#'

void superMario(void) {

    int height, spacer, mainIndexLoop, indexLoop, blockCounter = 1;

    do {

        printf("Inserire un valore tra 1 e 16 => ");
        scanf("%d", &height);

    } while( (height < 1) || (height > 16) );

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

int main(int argc, char* argv[]) {

    superMario();
    
    return (0);
 }