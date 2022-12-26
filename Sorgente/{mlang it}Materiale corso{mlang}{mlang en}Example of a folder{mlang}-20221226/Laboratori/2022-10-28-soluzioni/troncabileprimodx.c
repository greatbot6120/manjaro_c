#include <stdio.h>
#define BASE 10

int main() {
  int n;
  int i, primo;

  do
    scanf("%d", &n);
  while (n <= 0);

  primo = 1;

  while (n > 1 && primo) {
    /* e' un numero primo ? */
    if (n % 2 == 0 && n != 2)
      primo = 0;
    else {
      for (i = 3; i * i <= n && primo; i = i + 2)
        if (n % i == 0)
          primo = 0;
    }
    n = n / BASE;
  }
  if(n == 1) /* 1 non è primo per definizione */
    primo = 0;

  printf("%d\n", primo);
  return 0;
}
