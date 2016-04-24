#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXN 85

int main(int argc, const char * argv[]) {
    int t;
    double saw[4]={12.01, 1.008, 16.00, 14.01};

    scanf("%d", &t);
    while (t--){
        char s[MAXN];
        double ans = 0;
        int num, len, tp, i = 0;
        scanf("%s", s);
        len = strlen(s);
        while (i < len) {
            switch (s[i++]){
                case 'C': tp = 0;break;
                case 'H': tp = 1;break;
                case 'O': tp = 2;break;
                case 'N': tp = 3;break;
            }
            num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
                i++;
            }
            if (! num) num = 1;
            ans += num * saw[tp];
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}