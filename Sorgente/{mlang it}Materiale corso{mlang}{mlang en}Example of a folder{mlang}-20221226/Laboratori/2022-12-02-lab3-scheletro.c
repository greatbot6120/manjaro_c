#include<stdio.h>

#define DIMG 9
#define DIMQ 3
#define MINVAL 1
#define MINCHAR '1'
#define VUOTO 0
#define VUOTOINCHAR '_'
#define VUOTOOUTCHAR ' '
#define NELLOSCHEMA '*'

#define AVVIA 1
#define INSERISCI 2
#define CANCELLA 3
#define VERIFICA 4
#define CARICA 5
#define RIAVVIA 6
#define ESCI 0

/*copia il contenuto di una griglia in un'altra*/
void copiagriglia(int g_out[][DIMG], int g_in[][DIMG]);
/*leggi i valori di una griglia da tastiera*/
void acquisiscigriglia(int g[][DIMG]);
/*verifica che la griglia non abbia elementi fuori posto (in base alle regole del Sudoku)*/
int verificagriglia(int g[][DIMG]); 
/*verifica che la griglia non abbia caselle vuote*/
int grigliacompleta(int g[][DIMG]); 
/*verifica che la griglia sia consistente con lo schema iniziale*/
int controllaconsistenza(int g[][DIMG], int g_init[][DIMG]); 
/*visualizza griglia*/
void visualizzagriglia(int g[][DIMG], int g_init[][DIMG]);
/*aggiungi valore nella griglia corrente*/
void aggiungivalore(int g[][DIMG], int g_init[][DIMG]);
/*cancella valore dalla griglia corrente*/
void cancellavalore(int g[][DIMG], int g_init[][DIMG]);


int main(){
  int griglia[DIMG][DIMG], griglia_init[DIMG][DIMG];
  int scelta, partitaInCorso;

  acquisiscigriglia(griglia_init);
  copiagriglia(griglia, griglia_init);
  partitaInCorso = 1;

  do {
    printf("\n------------\n");
    printf("   SUDOKU\n");
    printf("------------\n");
    if(partitaInCorso)
      visualizzagriglia(griglia, griglia_init);
    printf("\nMenù:\n");
    printf("%d - avvia una nuova partita\n", AVVIA);
    if(partitaInCorso){
      printf("%d - inserisci valore\n", INSERISCI);
      printf("%d - cancella valore\n", CANCELLA);
      printf("%d - verifica la soluzione attuale\n", VERIFICA);
      printf("%d - carica una soluzione e verificala\n", CARICA);
      printf("%d - riavvia partita attuale\n", RIAVVIA);
    }
    printf("%d - esci\n", ESCI);
    printf("Inserire scelta: ");

    scanf("%d", &scelta);

    if(scelta == AVVIA){
      acquisiscigriglia(griglia_init);
      copiagriglia(griglia, griglia_init);
      partitaInCorso = 1;
    } else if(scelta == INSERISCI){
      aggiungivalore(griglia, griglia_init);
      if(grigliacompleta(griglia)){
        if(verificagriglia(griglia)){
          printf("VITTORIA!\n");
          partitaInCorso = 0;
        }
        else
          printf("La soluzione corrente è corretta\n");
      }
    } else if(scelta == CANCELLA){
      cancellavalore(griglia, griglia_init);
    } else if(scelta == VERIFICA){
      if(verificagriglia(griglia))
        printf("La soluzione corrente è corretta\n");
      else
        printf("La soluzione corrente NON è corretta\n");
    } else if(scelta == CARICA){
      acquisiscigriglia(griglia);
      if (controllaconsistenza(griglia, griglia_init))
        if(grigliacompleta(griglia))
          if(verificagriglia(griglia)){
            printf("VITTORIA!\n");
            partitaInCorso = 0;          }
          else      
            printf("La soluzione NON è corretta\n");
        else
          printf("La soluzione NON è completa\n");
      else
        printf("La stringa acquista non è consistente con lo schema iniziale\n");
    } else if(scelta == RIAVVIA){
      copiagriglia(griglia, griglia_init);
    } else if(scelta != ESCI){
      printf("Il valore inserito non corrisponde ad una voce del menù\n");
    }   
  } while(scelta != ESCI);

  printf("Arrivederci!\n");
  return 0;
}

void acquisiscigriglia(int g[][DIMG]) {

}

void copiagriglia(int g_out[][DIMG], int g_in[][DIMG]) {

}

int controllaconsistenza(int g[][DIMG], int g_init[][DIMG]) {
  int ok;
  return ok;
}

void visualizzagriglia(int g[][DIMG], int g_init[][DIMG]) {
  
}

int verificagriglia(int g[][DIMG]) {
  int ok;
  return ok;
}

int grigliacompleta(int g[][DIMG]){
  int ok;
  return ok;
}

void aggiungivalore(int g[][DIMG], int g_init[][DIMG]){

}

void cancellavalore(int g[][DIMG], int g_init[][DIMG]){

}