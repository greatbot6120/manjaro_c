#include <stdio.h>
#include <stdlib.h>
#include "placelib.h"

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

places_t* appendHead(places_t *currentHead) {

    places_t *newSiteHead = malloc(sizeof(places_t));

    if(newSiteHead != NULL) {

        printf("Enter a new site >> ");
        scanf("%s", newSiteHead -> site);
        newSiteHead -> x = 1;
        newSiteHead -> y = 1;
        
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

int main() {

    places_t *starter;
    appendHead(starter);
    appendHead(starter);
    appendHead(starter);


    return (0);
}