#include <stdio.h>
#define BASE 10
#define PAD '0'

int main() {
  int num, k;
  int val, i, ncifre;

  do
    scanf("%d", &num);
  while (num <= 0);

  do
    scanf("%d", &k);
  while (k <= 0);

  /* conto le cifre di 'val' */
  val = num;
  i = 0;
  while (val > 0) {
    val = val / BASE;
    i++;
  }

  /* stampo i caratteri di padding e poi il numero */
  for (; k > i; i++)
    printf("%c", PAD);
  printf("%d\n", num);

  return 0;
}
