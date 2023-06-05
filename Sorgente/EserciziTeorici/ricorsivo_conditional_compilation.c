#include <stdio.h>
#define TRACE 1 

int ricMultiply(int m, int n) {

    int res; 
	static int trace = 0;

    #ifdef TRACE
        printf(": Entering %d >> m = %d, n = %d\n", trace, m, n);
    #endif

    /* caso base */
    if(n == 1) {

        res = m;

    } else {

        /* passo ricorsivo */
		trace++;
        res = m + ricMultiply(m, n - 1);

		#ifdef TRACE
        	printf(": Leaving %d >> m = %d, n = %d, res = %d\n", trace, m, n, res);
		#endif
	}
	 
	return(res);
}

int main(int argc, char* arv[]) {

	ricMultiply(5,10);
}
