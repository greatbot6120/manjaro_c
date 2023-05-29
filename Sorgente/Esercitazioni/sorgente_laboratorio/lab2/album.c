/*
    Si vuole realizzare un programma per la gestione di un archivio di album
    musicali (al massimo 100). Ogni album è caratterizzato da un titolo ed un
    autore (entrambve le stringhe di al massimo 30 caratteri), un anno di 
    pubblicazione, il numero di tracce, la durata complessiva (in termini di
    ore, minuti, secondi); infine, si vuole memorizzare anche il prezzo
    dell'album (un valore float).
    Definire un tipo di dato per rappresentare l'archivio di album. In seguito 
    scrivere un programma che chieda all'utente prima il numero di album da
    inserire e poi i dati di ciascun album (assumendo che l'utente inserisca
    correttamente i dati). Il programma visualizza i dati dell'album di durata
    massima; se sono presenti più album di stessa durata massima il programma
    visualizzaerà i dati del primo di essi (VARIANTE: il programma visualizza i
    dati di tutti gli album di durata massima, se ne sono stati trovati più di
    uno).
    In seguito il programma chiede il nome di un autore e visualizza i titoli di
    tutti gli album pubblicati da questo. Infine il programma visualizza
    l'autore che ha pubblicato più album; se più autori hanno lo stesso numero 
    di album, si visualizzi il primo.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_STR 30
#define MAX_ALBUM 100

typedef struct {

    char title[MAX_STR + 1];
    char author[MAX_STR + 1];
    int year, numTracks, hours, minutes, seconds;
    float timeWrapper; /* facilita il confronto fra le lunghezze degli album singoli */
    float price;

} album_t;

/* function prototypes */
void fillTest(void);
void mostAlbums(album_t *albums, const int numAlbums);
void printMax(album_t *albumTest, const int higherLength);
void findMax(album_t *currentAlbum, const int totalAlbums);
void fillAlbum(const int numAlbums);
void album(void);

/* Testare con valori predefiniti */
void fillTest(void) {

    album_t albumSet[MAX_ALBUM];

    strcpy(albumSet[0].title, "Souvlaki");
    strcpy(albumSet[0].author, "Slowdive");
    albumSet[0].year = 1993;
    albumSet[0].numTracks = 10;
    albumSet[0].hours = 0;
    albumSet[0].minutes = 40;
    albumSet[0].seconds = 33;
    albumSet[0].timeWrapper = (albumSet[0].hours * 60) + 
                              (albumSet[0].minutes) + 
                              ( ((float) (albumSet[0].seconds)) / 60);
    albumSet[0].price = 99.65;

    strcpy(albumSet[1].title, "All Things Must Pass");
    strcpy(albumSet[1].author, "George Harrison");
    albumSet[1].year = 1970;
    albumSet[1].numTracks = 28;
    albumSet[1].hours = 2;
    albumSet[1].minutes = 5;
    albumSet[1].seconds = 0;
    albumSet[1].timeWrapper = (albumSet[1].hours * 60) + 
                              (albumSet[1].minutes) + 
                              ( ((float) (albumSet[1].seconds)) / 60);
    albumSet[1].price = 104.78;

    strcpy(albumSet[2].title, "The End Of Comedy");
    strcpy(albumSet[2].author, "Drugdealer");
    albumSet[2].year = 2016;
    albumSet[2].numTracks = 10;
    albumSet[2].hours = 0;
    albumSet[2].minutes = 31;
    albumSet[2].seconds = 5;
    albumSet[2].timeWrapper = (albumSet[2].hours * 60) + 
                              (albumSet[2].minutes) + 
                              ( ((float) (albumSet[2].seconds)) / 60);
    albumSet[2].price = 65.32;

    strcpy(albumSet[3].title, "THE STATEMENT");
    strcpy(albumSet[3].author, "DONT BLINK");
    albumSet[3].year = 2023;
    albumSet[3].numTracks = 13;
    albumSet[3].hours = 0;
    albumSet[3].minutes = 44;
    albumSet[3].seconds = 19;
    albumSet[3].timeWrapper = (albumSet[3].hours * 60) + 
                              (albumSet[3].minutes) + 
                              ( ((float) (albumSet[3].seconds)) / 60);
    albumSet[3].price = 42.25;

    strcpy(albumSet[4].title, "Siamese Dream");
    strcpy(albumSet[4].author, "The Smashing Pumpkins");
    albumSet[4].year = 1993;
    albumSet[4].numTracks = 13;
    albumSet[4].hours = 1;
    albumSet[4].minutes = 2;
    albumSet[4].seconds = 0;
    albumSet[4].timeWrapper = (albumSet[4].hours * 60) + 
                              (albumSet[4].minutes) + 
                              ( ((float) (albumSet[4].seconds)) / 60);
    albumSet[4].price = 199.25;

    strcpy(albumSet[5].title, "Living In The Material World");
    strcpy(albumSet[5].author, "George Harrison");
    albumSet[5].year = 1973;
    albumSet[5].numTracks = 14;
    albumSet[5].hours = 0;
    albumSet[5].minutes = 53;
    albumSet[5].seconds = 53;
    albumSet[5].timeWrapper = (albumSet[5].hours * 60) + 
                              (albumSet[5].minutes) + 
                              ( ((float) (albumSet[5].seconds)) / 60);
    albumSet[5].price = 199.25;

    findMax(albumSet, 6);
}

void mostAlbums(album_t *albums, const int total) {

    /* dichiariamo un array per metterci il numero di album di uno stesso artista */
    int numOfAlbumsIndex, albumIndex, equalityCounter, numOfAlbums[MAX_ALBUM];

    for(numOfAlbumsIndex = 0; numOfAlbumsIndex < total; numOfAlbumsIndex++) {

        for(albumIndex = numOfAlbumsIndex, equalityCounter = 1; albumIndex < total - 1; albumIndex++) {

            numOfAlbums[numOfAlbumsIndex] = equalityCounter;

            if( (albums[numOfAlbumsIndex].author) == (albums[albumIndex + 1].author) ) {

                numOfAlbums[numOfAlbumsIndex]++;
            }
        }
    }
    

    for(albumIndex = 0; albumIndex < total; albumIndex++) {

        printf("%d\t", numOfAlbums[albumIndex]);
    }

    printf("\n");
}

void printMax(album_t *albumTest, const int higherLength) {

    printf("Title of album N.%d >> %s\n", higherLength + 1, albumTest[higherLength].title);
    printf("Author of album N.%d >> %s\n", higherLength + 1, albumTest[higherLength].author);
    printf("Year of publication of album N.%d >> %d\n", higherLength + 1, albumTest[higherLength].year);
    printf("Number of tracks of album N.%d >> %d\n", higherLength + 1, albumTest[higherLength].numTracks);
    printf("Album N.%d is %d hours, %d minutes and %d seconds long\n", higherLength + 1, albumTest[higherLength].hours, albumTest[higherLength].minutes, albumTest[higherLength].seconds);
    printf("The album N.%d is worth %.2f $\n", higherLength + 1, albumTest[higherLength].price);
    printf("\n");
}

/* cerca l'album più lungo */
void findMax(album_t *currentAlbum, const int totalAlbums) {

    char choiceAuthor[MAX_STR];
    int albumIndex;
    float maxLength = 0;

    for(albumIndex = 1; albumIndex < totalAlbums; albumIndex++) {

        /* usiamo timeWrapper per comodità di confronto fra valori */
        if( (currentAlbum[albumIndex].timeWrapper > currentAlbum[albumIndex - 1].timeWrapper) && 
            (currentAlbum[albumIndex].timeWrapper > maxLength) ) {
            
            maxLength = currentAlbum[albumIndex].timeWrapper;
        }
    }

    /* print degli album con il valore massimo */
    printf("ALBUM DI DURATA MASSIMA:\n \n");

    for(albumIndex = 0; albumIndex < totalAlbums; albumIndex++) {

        if(currentAlbum[albumIndex].timeWrapper == maxLength) {

            printMax(currentAlbum, albumIndex);
        }
    }

    /* print degli album di uno stesso autore */
    printf("Inserire un autore >> ");
    scanf(" %[^\n]", choiceAuthor);
    printf("\nALBUM PUBBLICATI DA %s:\n \n", choiceAuthor); /* case sensitive */

    for(albumIndex = 0; albumIndex < totalAlbums; albumIndex++) {

        if( strcmp(currentAlbum[albumIndex].author, choiceAuthor) == 0 ) {

            printMax(currentAlbum, albumIndex);
        }
    }

    mostAlbums(currentAlbum, totalAlbums);
}

void fillAlbum(const int numAlbums) {

    album_t albumSet[MAX_ALBUM];
    int albumIndex;

    /* input dati album */
    for(albumIndex = 0; albumIndex < numAlbums; albumIndex++) {

        printf("Inserire il titolo dell'album N.%d >> ", albumIndex + 1);
        scanf(" %[^\n]", albumSet[albumIndex].title);

        printf("Inserire l'autore dell'album N.%d >> ", albumIndex + 1);
        scanf(" %[^\n]", albumSet[albumIndex].author);

        printf("Inserire l'anno di pubblicazione dell'album N.%d >> ", albumIndex + 1);
        scanf(" %d", &albumSet[albumIndex].year);

        printf("Inserire il numero di tracce dell'album N.%d >> ", albumIndex + 1);
        scanf(" %d", &albumSet[albumIndex].numTracks);

        printf("Inserire ore minuti e secondi dell'album N.%d >> ", albumIndex + 1);
        scanf(" %d%d%d", &albumSet[albumIndex].hours, &albumSet[albumIndex].minutes, &albumSet[albumIndex].seconds);
    
        printf("Inserire il prezzo dell'album N.%d >> ", albumIndex + 1);
        scanf(" %f", &albumSet[albumIndex].price);

        printf("\n");
    }

    findMax(albumSet, numAlbums);
}

/* check numero di album da inserire */
void album(void) {

    int index;
    
    do {

        printf("Quanti album vuoi inserire? (0-100) >> ");
        scanf("%d", &index);

    } while( (index <= 0) || (index > 100) );

    fillAlbum(index);
}

int main(int argc, char* argv[]) {

    /* album(); */
    fillTest();

    return (0);
}