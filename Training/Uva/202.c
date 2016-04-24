#include <stdio.h>
#include "string.h"
#define MAXN 3010

int main(void) {
    int decimals[MAXN], mark[MAXN];
    int a, b, m;

    while (scanf("%d%d", &a, &b) == 2) {
        memset(mark, 0, sizeof(mark));
        memset(decimals, 0, sizeof(decimals));
        int count = 0;
        decimals[count++] = a / b;
        m = a % b;
        while (!mark[m] && m) {
            mark[m] = count;
            decimals[count++] = m * 10 / b;
            m = m * 10 % b;
        }
        printf("%d/%d = %d.", a, b, decimals[0]);
        for (int i = 1; i < count && i <= 50; i++) {
            if (m && mark[m] == i) printf("(");
            printf("%d", decimals[i]);
        }
        if (!m) printf("(0");
        if (count > 50) printf("...");
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n", !m ? 1 : count-mark[m]);
    }
    
    return 0;
}