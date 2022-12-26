#include <stdio.h>
#define MAX 50

int main(){
  int n, lun, i;
  char seq1[MAX+1], seq2[MAX+1];

  scanf("%s", seq1);

  for(lun=0; seq1[lun]!='\0'; lun++);

  scanf("%d", &n);              /* oppure                     */
  while(n<=0 || n >= lun){      /* do                         */
    printf("Errore\n");         /*   scanf("%d", &n);         */
    scanf("%d", &n);            /* while(n <= 0 || n > lun);  */
  }

  for(i=0; seq1[i]!='\0'; i++){
    seq2[(i+n)%lun] = seq1[i];
  }
  seq2[i]='\0';

  printf("%s\n", seq2);

  return 0;
}
