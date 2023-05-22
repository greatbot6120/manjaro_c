#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {

    char seq_one[] = {"Malilin,Ivan,Ivanovich"};
    char *first, *middle, *last, *last_two;

    first = strtok(seq_one, ",");
    middle = strtok(NULL, ",");
    last = strtok(NULL, ",");
    last_two = strtok(NULL, ",");

    printf("%s %s %s\n", first, middle, last);
    
    if(last_two == NULL) {

        printf("We're done\n");
    }

    if(seq_one[7] == '\0') {

        printf("True\n");
    }

    return (0);
}