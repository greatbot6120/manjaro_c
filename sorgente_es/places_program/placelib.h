#ifndef PLACELIB_H

    #define PLACELIB_H

    /* for debugging purposes*/
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

    void viewMenu(void);
    void appendHead(places_t **currentHead);
    void appendQueue(places_t **currentTail);
    void viewRoute(places_t *currentView);

#endif