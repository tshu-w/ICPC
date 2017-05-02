#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int w, q[50], n, t;
    char s[50];
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(s, 0, sizeof(s));
        int p = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &w);
            while (s[p] == ')') p++;
            s[p] = '(';
            s[i + w] = ')';
            p++;
        }
        for (int i = 0; i < 2 * n; i++) 
            if (s[i] == ')') {
                int l = 0, r = 1, p = i;
                while (p && r - l) {
                    p--;
                    if (s[p] == '(') l++;
                    else r++;
                }
                printf("%d ", l);
            }
        printf("\n");
    }
    return 0;
}