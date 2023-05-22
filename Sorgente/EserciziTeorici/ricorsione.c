#include <stdio.h>

int ricMultiply(int m, int n) {

    int res;

    if(n == 1) {

        res = m;

    } else {

        res = m + ricMultiply(m, n - 1);
    }

    return(res);
}

int main(int argc, char* argv[]) {

    printf("%d\n", ricMultiply(6, 3));

    return (0);
}