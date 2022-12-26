#include <stdio.h>
#define BLOCK '#'
#define MIN 1
#define MAX 16

int main() {
  int h; /* altezza */
  int i, j;

  do {
    scanf("%d", &h);
  } while (h < MIN || h > MAX);

  for (i = 1; i <= h; i++) {
    for (j = 0; j < h - i; j++) /* spazi iniziali */
      printf(" ");

    for (j = 0; j < i; j++) /* i volte # */
      printf("%c", BLOCK);

    /* separatore */
    printf("  ");

    for (j = 0; j < i; j++) /* i volte # */
      printf("%c", BLOCK);

    printf("\n");
  }

  return 0;
}
