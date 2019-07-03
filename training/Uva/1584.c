#include <stdio.h>
#include "string.h"
#define MAXN 105

int less(const char * s, int p, int q);
int main(int argc, const char * argv[]) {
    int t;
    char s[MAXN];

    scanf("%d", &t);
    while (t--){
        scanf("%s", s);
        int ans = 0, n = strlen(s);
        for (int i = 1; i < n; i++)
            if (less(s, ans, i)) ans = i;
        for (int i = 0; i < n; i++)
            putchar(s[(ans+i)%n]);
        putchar('\n');
    }

    return 0;
}

int less(const char * s,int p, int q){
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        if (s[(i+p)%n] != s[(i+q)%n])
            return (s[(i+p)%n] > s[(i+q)%n]);

    return 0;
}