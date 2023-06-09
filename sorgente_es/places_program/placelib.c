#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "placelib.h"

/*
 *   TODO:
 *   - change scanf()s in selection of site to not skipping spaces 
 */

void viewMenu(places_t *headp) {
    
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
    scanf("%d", &menuSel);

    /* check right values */
    if( (menuSel < 1) || (menuSel > 14) ) {
        
        #if PLACE_TRACE
            printf(">> ERROR MENU SELECTION, NOT A VALID OPTION %s\n", PLACE_ERROR);
            exit(EXIT_FAILURE);
        #endif
    }

    switch(menuSel) {

        case (1):
            
            headp = appendHead(headp);
            viewMenu(headp);
            break;

        case (2):

            headp = appendQueue(headp);
            viewMenu(headp);
            break;
        
        case (3):

            headp = appendIndex(headp);
            viewMenu(headp);
            break;
        
        case (4):

            headp = deletePlace(headp);
            viewMenu();
            break;

        case (5):

            if(headp != NULL) {

                viewRoute(headp);
            
            } else {

                #if PLACE_TRACE
                    printf(">> ERROR, EMPTY LIST %s\n", PLACE_ERROR);
                    exit(EXIT_FAILURE);
                #endif
            }
            break;

        case (14):

            exit(EXIT_SUCCESS);

        default:
                
            #if PLACE_TRACE
                printf(">> CASE NOT YET DEFINED %s\n", PLACE_ERROR);
                exit(EXIT_FAILURE);
            #endif

            exit(EXIT_SUCCESS);

/*          
        case (6):
        case (7):
        case (8):
        case (9):
        case (10):
        case (11):
        case (12):
        case (13):
*/
    }
}

/* double pointer for propagating to caller actual parameter */
places_t* appendHead(places_t *currentHead) {

    places_t *newSiteHead = malloc(sizeof(places_t));
    int tempX, tempY;
    if(newSiteHead != NULL) {

        printf("Enter a new site >> ");
        scanf("%s", newSiteHead -> site);
        printf("Enter %s coordinates x and y respectively separated by a blank space >> ", newSiteHead -> site);
        scanf("%d%d", &tempX, &tempY);
        newSiteHead -> x = tempX;
        newSiteHead -> y = tempY;

        #if PLACE_TRACE
            printf(">> SUCCESSFULLY DEFINED NEW NODE ITEMS %s\n", PLACE_SUCCESS);
        #endif

        /* we assign at linkp the old head */
        newSiteHead -> linkp = currentHead;

        /* we assign the new head */
        currentHead = newSiteHead;
        
        #if PLACE_TRACE
            printf(">> SITE APPENDED ON HEAD SUCCESSFULLY %s\n", PLACE_SUCCESS);
        #endif

    } else {

        #if PLACE_TRACE
            printf(">> ERROR, NOT ENOUGH MEMORY (POINTER TO NULL) %s\n", PLACE_ERROR);
        #endif
    }

    printf("\n");
    return (currentHead);
}

places_t* appendIndex(places_t *currentHead) {

    places_t *tempNull;
    places_t *newSiteIndex = malloc(sizeof(places_t));
    int tempX, tempY, index;

    if(newSiteIndex != NULL) {
        
        printf("Enter the site index >> ");
        scanf("%d", &index);
        printf("Enter a new site >> ");
        scanf("%s", newSiteIndex -> site);
        printf("Enter %s coordinates x and y respectively separated by a blank space >> ", newSiteIndex -> site);
        scanf("%d%d", &tempX, &tempY);
        newSiteIndex -> x = tempX;
        newSiteIndex -> y = tempY;
        newSiteIndex -> linkp = NULL;

        if(currentHead == NULL) {

            currentHead = newSiteIndex;

            #if PLACE_TRACE
                printf(">> SITE APPENDED ON HEAD BECAUSE POINTER WAS NULL %s\n", PLACE_SUCCESS);
            #endif
        
        } else {

            tempNull = currentHead;

            /* index from zero like in arrays*/
            while(index > 1) {

                if(tempNull -> linkp != NULL) {

                    tempNull = tempNull -> linkp;
                    --index;
                
                } else {

                    #if PLACE_TRACE
                        printf(">> INDEX OUT OF BOUNDS %s\n", PLACE_ERROR);
                        exit(EXIT_FAILURE);
                    #endif
                }
            }
            
            newSiteIndex -> linkp = tempNull -> linkp;
            tempNull -> linkp = newSiteIndex;

            #if PLACE_TRACE
                printf(">> SITE APPENDED ON INDEX SUCCESSFULLY %s\n", PLACE_SUCCESS);
            #endif
        }   
    }

    printf("\n");
    return (currentHead);
}

places_t* appendQueue(places_t *currentHead) {

    places_t *tempNull;
    places_t *newSiteTail = malloc(sizeof(places_t));
    int tempX, tempY;

    if(newSiteTail != NULL) {

        printf("Enter a new site >> ");
        scanf("%s", newSiteTail -> site);
        printf("Enter %s coordinates x and y respectively separated by a blank space >> ", newSiteTail -> site);
        scanf("%d%d", &tempX, &tempY);
        newSiteTail -> x = tempX;
        newSiteTail -> y = tempY;
        newSiteTail -> linkp = NULL;
        
        #if PLACE_TRACE
            printf(">> SUCCESSFULLY DEFINED NEW NODE ITEMS %s\n", PLACE_SUCCESS);
        #endif

        if(currentHead == NULL) {

            currentHead = newSiteTail;

            #if PLACE_TRACE
                printf(">> SITE APPENDED ON HEAD BECAUSE POINTER WAS NULL %s\n", PLACE_SUCCESS);
            #endif

        } else {
            
            tempNull = currentHead;

            while(tempNull -> linkp != NULL) {

                tempNull = tempNull -> linkp;
            }

            tempNull -> linkp = newSiteTail;
            
            #if PLACE_TRACE
                printf(">> SITE APPENDED ON QUEUE SUCCESSFULLY %s\n", PLACE_SUCCESS);
            #endif
        }

    } else {
        
        #if PLACE_TRACE
            printf(">> ERROR, OUT OF MEMORY %s\n", PLACE_ERROR);
            exit(EXIT_FAILURE);
        #endif
    }

    printf("\n");
    return(currentHead);
    /*viewMenu();*/
}

places_t* deletePlace(places_t *currentHead) {

    places_t *tempNull;
    int index;

    printf("Enter the index of the site to delete >> ");
    scanf("%d", &index);
    
    if(currentHead != NULL) {

        tempNull = currentHead;

        while(index > 1) {

            if(tempNull -> linkp != NULL) {

                tempNull = tempNull -> linkp;
                --index;

            } else {

                #if PLACE_TRACE
                    printf(">> INDEX OUT OF BOUNDS %s\n", PLACE_ERROR);
                    exit(EXIT_FAILURE);
                #endif
            }
        }

        /* if we are trying to delete on head */
        if(tempNull == currentHead) {
            
            /* if we are trying to delete on head AND it's the only element in the list */
            if(currentHead -> linkp != NULL) {

                currentHead = currentHead -> linkp;
            }

            free(tempNull);

        } else if() {

            /* if we are trying to delete on queue */
            


        }
        
        
        
        

    } else {

        #if PLACE_TRACE
            printf(">> ERROR, EMPTY LIST NOTHING TO DEALLOCATE %s\n", PLACE_ERROR);
            exit(EXIT_FAILURE);
        #endif

    }









    return(currentHead);
}







void viewRoute(places_t *currentView) {

    printf("Here are you're sites with coordinates:\n\n");

    while(currentView != NULL) {

        printf("\tName: %s\n\tCoordinates: (%d,%d)\n\n",
               currentView -> site, currentView -> x, currentView -> y);

        currentView = currentView -> linkp;
    }

    printf("\n");
    /*viewMenu();*/
}
