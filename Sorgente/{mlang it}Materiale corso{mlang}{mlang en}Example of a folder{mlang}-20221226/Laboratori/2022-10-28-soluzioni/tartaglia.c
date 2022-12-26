#include <stdio.h>
#define MAX 10

int main(){
  int t[MAX][MAX];
  int i, j, dim;

  do
    scanf("%d", &dim);
  while(dim > MAX || dim <= 0);

  /* calcolo della matrice */
  t[0][0] = 1;
  for(i = 1; i < dim; i++){
    /* il primo 1 */
    t[i][0] = 1;
    /* i valori calcolati */
    for(j = 1; j < i; j++)
      t[i][j] = t[i-1][j-1]+t[i-1][j];
    /* l'ultimo 1 */
    t[i][j] = 1;
  }

  /* visualizzazione della matrice */
  for(i = 0; i < dim; i++){
    for(j = 0; j <= i; j++)
      printf("%d\t", t[i][j]);
    printf("\n");
  }

  return 0;
}
