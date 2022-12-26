#include <stdio.h>
#define MAX 10

/* versione 3 - senza matrice */
int main(){
  int t[MAX];
  int i,j,dim;

  do
    scanf("%d",&dim);
  while(dim > MAX || dim <= 0);

  /* calcolo della matrice */
  for (i=0; i<dim; i++){
    /* scorro all'indietro poichè per calcolare l'i-esimo valore 
       ho bisogno dei valori i e i-1 dell'iterazione precedente */
    for (j=i; j>=0; j--) 
      if((j==0)||(i==j))
        t[j]=1;
      else
        t[j]= t[j-1] + t[j];

    /* visualizzazione della riga della matrice */
    for(j=0; j<=i; j++)
      printf("%d\t", t[j]);
    printf("\n");
  }

  return 0;
}
