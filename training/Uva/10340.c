#include <stdio.h>
#include <string.h>
#define MAXN 101000

int Cmp(char *s, char *t) {
    int i = 0, j = 0;
    int s_len = strlen(s), t_len = strlen(t);
    while (i < s_len && j < t_len) {
        if (s[i] == t[j]) { i++; j++;}
        else j++;
    }
    return s_len == i;
}

int main(int argc, const char * argv[]) {
    char s[MAXN], t[MAXN];

    while (~scanf("%s%s", s, t)) {
        printf(Cmp(s, t)? "Yes\n" : "No\n");
    }
    
    return 0;
}