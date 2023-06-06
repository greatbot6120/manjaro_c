#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "placelib.h"

void newPlaces(void) {

    char selection;

    printf("Enter m for the menu or q to exit >> ");
    selection = getchar();
    printf("\n");

    switch(selection) {

        case (PLACE_MENU):

            viewMenu();
            break;
        
        case (PLACE_QUIT):

            exit(EXIT_SUCCESS);

        default:

            #ifdef PLACE_TRACE
                printf(">> ERROR MAIN SELECTION %s\n", PLACE_ERROR);
                exit(EXIT_FAILURE);
            #endif
    }
}

int main(int argc, char* argv[]) {

    newPlaces();
    
    return(0);
}