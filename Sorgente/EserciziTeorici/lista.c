#include <stdio.h>
#include <stdlib.h>
#define NOTE 4

typedef struct nodes {

    char note[NOTE];
    struct nodes *linkp;

} node_t;

void createList(void) {

    int i;

    node_t *startScale, *current, *newNote;

    startScale = (node_t *) malloc(sizeof(node_t));
    scanf("%s", startScale -> note);
    current = startScale; 
    
    for(i = 0; i < 7; ++i) {

        /* alloco memoria */
        newNote = (node_t *) malloc(sizeof(node_t));

        /* impostiamo la coda */
        newNote -> linkp = NULL;
        
        /* inizializzo la nota */
        scanf("%s", newNote -> note);

        /* collego il puntatore al nodo precedente */
        current -> linkp = newNote;

        /* aggiorno il puntatore */
        current = newNote;
    }

    printf("\n");

    while(startScale != NULL) {

        printf("%s\n", startScale -> note);
        startScale = startScale -> linkp;
    }

    printf("\n ✔");
}

int main() {

    createList();

    return (0);
}
