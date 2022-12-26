#include <stdio.h>
#define MAX 10

/* versione 2 */
int main(){
  int t[MAX][MAX];
  int i, j, dim;

  do
    scanf("%d", &dim);
  while(dim > MAX || dim <= 0);

  /* calcolo della matrice */
  for(i = 0; i < dim; i++)
    for(j = 0; j <= i; j++)
      if((j == 0) || (i == j))
        t[i][j] = 1;
      else
        t[i][j] = t[i-1][j-1]+t[i-1][j];

  /* visualizzazione della matrice */
  for(i = 0; i < dim; i++){
    for(j = 0; j <= i; j++)
      printf("%d\t", t[i][j]);
    printf("\n");
  }

  return 0;
}
