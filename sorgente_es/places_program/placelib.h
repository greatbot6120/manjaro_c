#ifndef PLACELIB_H

    #define PLACELIB_H

    /* for debugging purposes*/
    #define PLACE_AFFIRMATIVE 'y'
    #define PLACE_NEGATIVE `n`
    #define PLACE_QUIT 'q'
    #define PLACE_MENU 'm'
    #define PLACE_TRACE 1
    #define PLACE_SITE 30
    #define PLACE_SUCCESS "✔"
    #define PLACE_ERROR "✗"
   
    typedef struct places {

        char site[PLACE_SITE + 1];
        int x, y;
        struct places *linkp;

    } places_t;

    void viewMenu(places_t *headp);
    places_t* appendHead(places_t *currentHead);
    places_t* appendIndex(places_t *currentHead);
    places_t* appendQueue(places_t *currentHead);
    places_t* deletePlace(places_t *currentHead);
    void viewRoute(places_t *currentView);

#endif