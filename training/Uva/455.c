#include <stdio.h>
#include "string.h"
#define MAXN 85

int main(int argc, const char * argv[]) {
    char s[MAXN];
    int t;

    scanf("%d", &t);
    while (t--){
        int i;
        scanf("%s", s);
        int len = strlen(s), k;
        for (i = 1; i <= (len/2); i++)
        if ((len % i)== 0){
            int flag = 1;
            for (int j = 0; j < i; j++) {
                k = j;
                while ((k+i) < len) {
                    if (s[k] != s[k + i]) {flag = 0;break;}
                    k += i;
                }
                if (!flag) break;
            }
            if (flag) {printf("%d\n", i);break;}
        }
        if (i > (len / 2)) printf("%d\n", len);
        if (t) putchar('\n');
    }

    return 0;
}