/*
    Scrivere un programma che acquisita una stringa di al più 30 caratteri,
    individui la sottostringa più lunga in essa contenuta, senza caratteri
    ripetuti. Il programma visualizza la lunghezza di tale sottostringa,
    seguita da un carattere a capo.
    Realizzare la propria soluzione organizzandola in sottoprogrammi, come
    ritenuto più opportuno.
 */

#include <stdio.h>
#include <string.h>
#define MAX_STR 30



void subString(void) {

    char seq_one[MAX_STR + 1] = "Sottostringa distintamente";
    int mainLoop, indexLoop, subIndexLoop, tempStart, tempEnd, tempLonger = 0, length = strlen(seq_one);

    for(mainLoop = 0; mainLoop != '\0'; mainLoop++) {

        for(indexLoop = mainLoop; indexLoop < length - 1; indexLoop++) {

            for(subIndexLoop = indexLoop + 1; subIndexLoop < length; subIndexLoop++) {

                if(seq_one[indexLoop] != seq_one[subIndexLoop]) {

                    if( tempLonger < (subIndexLoop - indexLoop) ) {

                        tempStart = indexLoop;
                        tempEnd = subIndexLoop;
                        tempLonger = tempEnd - tempStart;
                    }

                } else {

                    mainLoop = subIndexLoop - 1;
                    indexLoop = length;
                    subIndexLoop = length;
                }
            }
        }  
    }

    for(indexLoop = tempStart; indexLoop <= tempEnd; indexLoop++) {

        printf("%c", seq_one[indexLoop]);
    }

    printf("\n");
}

int main(int argc, char* argv[]) {

    subString();

    return (0);
}
