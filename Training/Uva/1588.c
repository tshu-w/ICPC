#include <stdio.h>
#include "string.h"

int max(int a,int b) {
    return (a > b)? a : b;
}
int min(int a,int b) {
    return (a < b)? a : b;
}
int main(int argc, const char * argv[]) {
    char s[2][110];

    while (scanf("%s%s",s[0], s[1]) == 2) {
        int len1 = strlen(s[0]), len2 = strlen(s[1]);
        int ans = len1 + len2;
        for (int i = 1; i < len1+len2; i++) {
            int flag = 1;
            int left = max(i, len1);
            int right = min(i + len1 - 1, len1 + len2 - 1);
            for (int j = left; j <= right && flag; j++) {
                int x = j - i;
                int y = j - len1;
                if (s[0][x] - '0' + s[1][y] - '0' > 3) flag = 0;
            }
            if ((flag) && ans > len1 + len2 - (right - left) -1) ans = len1 + len2 - (right - left) - 1;
        }
        printf("%d\n", ans); 
    }

    return 0;
}