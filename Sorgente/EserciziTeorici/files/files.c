#include <stdio.h>
#define STR_SIZE 80

void backup(void) {

    char single_c, in_name[STR_SIZE], out_name[STR_SIZE];
    FILE *in, *out;

    printf("Enter name of file you want to backup >> ");

    /* si acquisisce il nome del file da copiare e aprirlo in lettura */
    for( scanf("%s", in_name); (in = fopen(in_name, "r")) == NULL; scanf("%s", in_name) ) {

        printf("Cannot open file %s, for input\nRe-enter file name >> ", in_name);
    }

    printf("Enter name for the backup copy >> ");

    /* si acquisisce il nome del file su cui fare il backup */
    for( scanf("%s", out_name); (out = fopen(out_name, "w")) == NULL; scanf("%s", out_name) ) {
        
        printf("Cannot open file %s, for output\nRe-enter file name >> ", out_name);
    }

    /* copia un carattere alla volta */
    for( single_c = getc(in); single_c != EOF; single_c = getc(in) ) {

        putc(single_c, out);
    }

    fclose(in);
    fclose(out);

    printf("Copied %s to %s.\n", in_name, out_name);

}

int main() {

    backup();

    return (0);
}