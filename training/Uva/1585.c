#include <stdio.h>
#include <string.h>
#define MAXN 85

int main(int argc, const char * argv[]) {
    char s[MAXN];
    int t;
    
    scanf("%d" ,&t);
    while (t--){
        scanf("%s", s);
        unsigned long score = 0L;
        int n = strlen(s), t = 0, k = 0;
        while (t < n){
            while ( s[t] != 'X' && t<n) {
                t++;
                score += ++k;
            };
            while (s[t] == 'X' && t<n) t++;
            k = 0;
        }
        printf("%lu\n", score);
    }

    return 0;
}