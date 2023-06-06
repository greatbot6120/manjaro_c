#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "placelib.h"

void viewMenu(void) {
    
    int menuSel;
    
    printf("\t\tMENU:\n\n"
           "1. Inserire in testa una nuova località\n"
           "2. Inserire in coda una nuova località\n"
           "3. Inserire in una specificata posizione una nuova località\n"
           "4. Cancellare una località nella lista\n"
           "5. Visualizzare l’intero percorso\n"
           "6. Visualizzare la lunghezza complessiva dell’itinerario\n"
           "7. Visualizzare la coppia di località (anche non consecutive nel percorso) la "
           "cui distanza è maggiore di qualsiasi altra coppia\n"
           "8. Ricerca località per nome\n"
           "9. Calcola la cornice intorno al percorso\n"
           "10. Salvare percorso su file di testo\n"
           "11. Caricare percorso da file di testo\n"
           "12. Salvare percorso su file binario\n"
           "13. Caricare percorso da file binario\n"
           "14. Uscita\n\n"
           "Enter a selection (1-14) >> ");
    
    /* check right values */
    for( scanf("%d", &menuSel); (menuSel < 1) || (menuSel > 14); scanf("%d", &menuSel) ) {

        #ifdef PLACE_TRACE
            printf(">> ERROR MENU SELECTION %s\n", PLACE_ERROR);
            exit(EXIT_FAILURE);
        #endif
    }

    switch(menuSel) {

        case (1):
            
            places_t *headp;
            appendHead(&headp);

        case (2):

            places_t *queuep;
            appendQueue(&queuep);
        
        case (5):

            places_t *headView;
            viewRoute(headView);
/*          
        case (3):
        case (4):
        case (6):
        case (7):
        case (8):
        case (9):
        case (10):
        case (11):
        case (12):
        case (13):
*/
        case (14):

            exit(EXIT_SUCCESS);
    }
}

/* double pointer for propagating to caller actual parameter */
void appendHead(places_t **currentHead) {

    places_t *newSiteHead = malloc(sizeof(places_t));
    int tempX, tempY;
    
    if(newSiteHead != NULL) {
        
        printf("Enter a new site >> ");
        scanf("%s", newSiteHead -> site);
        printf("Enter %s coordinates x and y respectively separated by a blank >> ", newSiteHead -> site);
        scanf("%d%d", &tempX, &tempY);
        newSiteHead -> x = tempX;
        newSiteHead -> y = tempY;

        #ifdef PLACE_TRACE
            printf(">> SUCCESSFULLY DEFINED NEW NODE ITEMS %s\n", PLACE_SUCCESS);
        #endif

        newSiteHead -> linkp = *currentHead;
        *currentHead = newSiteHead;

        #ifdef PLACE_TRACE
            printf(">> SITE APPENDED ON HEAD SUCCESSFULLY %s\n", PLACE_SUCCESS);
        #endif
    }

    printf("\n");
    sleep(2);
    viewMenu();
}

void appendQueue(places_t **currentTail) {

    places_t *newSiteTail, *tempNull; 
    newSiteTail = malloc(sizeof(places_t));
    int tempX, tempY;
    
    if(newSiteTail != NULL) {
        
        printf("Enter a new site >> ");
        scanf("%s", newSiteTail -> site);
        printf("Enter %s coordinates x and y respectively separated by a blank >> ", newSiteTail -> site);
        scanf("%d%d", &tempX, &tempY);
        newSiteTail -> x = tempX;
        newSiteTail -> y = tempY;
        newSiteTail -> linkp = NULL;

        #ifdef PLACE_TRACE
            printf(">> SUCCESSFULLY DEFINED NEW NODE ITEMS %s\n", PLACE_SUCCESS);
        #endif

        if(*currentTail == NULL) {
            
            *currentTail = newSiteTail;
        
        } else {
            
            /* searching for the last node */
            for( tempNull = *currentTail; (tempNull -> linkp) != NULL; tempNull = tempNull -> linkp ) {

                tempNull -> linkp = newSiteTail;                
            }
        }

        #ifdef PLACE_TRACE
            printf(">> SITE APPENDED ON QUEUE SUCCESSFULLY %s\n", PLACE_SUCCESS);
        #endif
    }

    printf("\n");
    sleep(2);
    viewMenu();
}

void viewRoute(places_t *currentView) {

    while(currentView != NULL) {

        printf("Here are you're sites with coordinates:\n\tName: %s\n\tCoordinates: (%d,%d)\n",
               currentView -> site, currentView -> x, currentView -> y);

        currentView = currentView -> linkp;
    }

    printf("\n");
    sleep(2);
    viewMenu();
}
