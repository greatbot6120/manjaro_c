#include <stdio.h>
#include <stdlib.h>
#define PLACE_SUCCESS "✔"
#define PLACE_ERROR "✗"
#define PLACE_SITE 30

typedef struct places {
    
    char site[PLACE_SITE + 1];
    int x, y;
    struct places *linkp;

} places_t;

void viewRoute(places_t *currentView) {

    while(currentView != NULL) {

        printf("Here are you're sites with coordinates:\n\n\tName: %s\n\tCoordinates: (%d,%d)\n\n",
               currentView -> site, currentView -> x, currentView -> y);

        currentView = currentView -> linkp;
    }

    printf("\n");
}

places_t* appendQueue(places_t *currentHead) {

    places_t *tempNull;
    places_t *newSiteTail = malloc(sizeof(places_t));

    if(newSiteTail != NULL) {

        printf("Enter a new site >> ");
        scanf("%s", newSiteTail -> site);
        newSiteTail -> x = 1;
        newSiteTail -> y = 1;
        newSiteTail -> linkp = NULL;
        
        printf(">> SUCCESSFULLY DEFINED NEW NODE ITEMS %s\n", PLACE_SUCCESS);

        if(currentHead == NULL) {

            currentHead = newSiteTail;
            printf(">> SITE APPENDED ON HEAD BECAUSE POINTER WAS NULL %s\n", PLACE_SUCCESS);

        } else {
            
            tempNull = currentHead;

            while(tempNull -> linkp != NULL) {

                tempNull = tempNull -> linkp;
            }

            tempNull -> linkp = newSiteTail;

            printf(">> SITE APPENDED ON QUEUE SUCCESSFULLY %s\n", PLACE_SUCCESS);
        }

    } else {

        printf(">> ERROR OUT OF MEMORY %s\n", PLACE_ERROR);
        exit(EXIT_FAILURE);
    }

    return (currentHead);
}

places_t* appendHead(places_t *currentHead) {

    places_t *newSiteHead = malloc(sizeof(places_t));

    if(newSiteHead != NULL) {

        printf("Enter a new site >> ");
        scanf("%s", newSiteHead -> site);
        newSiteHead -> x = 1;
        newSiteHead -> y = 1;
        
        printf(">> SUCCESSFULLY DEFINED NEW NODE ITEMS %s\n", PLACE_SUCCESS);
        

        /* we assign at linkp the old head */
        newSiteHead -> linkp = currentHead;

        /* we assign the new head */
        currentHead = newSiteHead;

        printf(">> SITE APPENDED ON HEAD SUCCESSFULLY %s\n", PLACE_SUCCESS);
    
    } else {

        printf(">> ERROR, NOT ENOUGH MEMORY (POINTER TO NULL) %s\n", PLACE_ERROR);
    }

    printf("\n");
    return (currentHead);
}

int main() {
    
    /*
        Should be:f
        3. TORINO
        1. MILANO
        2. NAPOLI
        4. VERONA
     */

    places_t *starter = NULL;

    starter = appendHead(starter);
    starter = appendQueue(starter);
    starter = appendHead(starter);
    starter = appendQueue(starter);
    viewRoute(starter);

    return (0);
}