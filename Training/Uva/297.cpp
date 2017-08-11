// written at 13:27 on 07 Aug 2017
#include <bits/stdc++.h>
using namespace std;

const int len = 32;
const int maxn = 1024 + 10;

char s[maxn];
int buff[len][len], cnt;

void draw(char s[], int &p, int r, int c, int w) {
    if (w == 0) return;
    char ch = s[p++];
    if (ch == 'p') {
        draw(s, p, r, c, w / 2);
        draw(s, p, r, c + w / 2, w / 2);
        draw(s, p, r + w / 2, c, w / 2);
        draw(s, p, r + w / 2, c + w / 2, w / 2);
    }
    else if (ch == 'f') {
        for (int i = r; i < r + w; i++)
            for (int j = c; j < c + w;j++)
                if (buff[i][j] == 0) {
                    buff[i][j] = 1;
                    cnt++;
                }
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(buff, 0, sizeof(buff));
        cnt = 0;
        for (int i = 0; i < 2; i++) {
            scanf("%s", s);
            int p = 0;
            draw(s, p, 0, 0, len);
        }
        printf("There are %d black pixels.\n", cnt);
    }
    return 0;
}
