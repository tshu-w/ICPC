#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
const int MAX_N = 1024 + 10;
const int B = 9973;

int w, h, p, image[MAX_N][MAX_N],  pattern[MAX_N][MAX_N], tmp[MAX_N][MAX_N];
char img[MAX_N][MAX_N], ptn[MAX_N][MAX_N];
ull hsh[8], img_hsh[MAX_N][MAX_N];

inline int base64(char ch) {
    if ('A' <= ch && ch <= 'Z')
        return ch - 'A';
    if ('a' <= ch && ch <= 'z')
        return ch - 'a' + 26;
    if ('0' <= ch && ch <= '9')
        return ch - '0' + 52;
    return ch == '+' ? 62 : 63;
}

inline void base64_to_bit(char field[MAX_N][MAX_N], int bit[MAX_N][MAX_N], int h) {
    for (int i = 0; i < h; i++)
        for (int j = 0; j < h; j++)
            bit[i][j] = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; field[i][j]; j++) {
            const int x = base64(field[i][j]);
            for (int k = 0; k < 6; k++)
                bit[i][j * 6 + 5 - k] = x >> k & 1;
        }
}

int main() {
    while (scanf("%d%d%d", &w, &h, &p), w) {
        for (int i = 0; i < h; i++)
            scanf("%s", img[i]);
        for (int i = 0; i < p; i++)
            scanf("%s", ptn[i]);
        base64_to_bit(img, image, h);
        base64_to_bit(ptn, pattern, p);
        for (int d = 0; d < 8; d++) {
            for (int i = 0; i < p; i++)
                for (int j = 0; j < p; j++)
                    tmp[i][j] = pattern[i][j];
            for (int i = 0; i < p; i++)
                for (int j = 0; j < p; j++)
                    pattern[p - j - 1][i] = tmp[i][j];
            if (d == 4) {
                for (int i = 0; i < p; i++)
                    for (int j = 0; j < p; j++)
                        tmp[i][j] = pattern[i][j];
                for (int i = 0; i < p; i++)
                    for (int j = 0; j < p; j++)
                        pattern[i][p - j - 1] = tmp[i][j];
            }
            hsh[d] = 0;
            for (int i = 0; i < p; i++)
                for (int j = 0; j < p; j++)
                    hsh[d] = hsh[d] * B + pattern[i][j];
        }
        int ans = 0;
        ull t1 = 1;
        for (int i = 0; i < p; i++) t1 = t1 * B;
        for (int i = 0; i < h; i++) {
            ull e = 0;
            for (int j = 0; j < p; j++) e = e * B + image[i][j];
            for (int j = 0; j + p <= w; j++) {
                img_hsh[i][j] = e;
                if (j + p < w) e = e * B + image[i][j + p] - t1 * image[i][j];
            }
        }
        ull t2 = 1;
        for (int i = 0; i < p; i++) t2 = t2 * t1;
        for (int j = 0; j + p <= w; j++) {
            ull e = 0;
            for (int i = 0; i < p; i++) e = e * t1 + img_hsh[i][j];
            for (int i = 0; i + p <= h; i++) {
                for (int d = 0; d < 8; d++)
                    if (hsh[d] == e) {
                        ++ans;
                        break;
                    }
                if (i + p < h) e = e * t1 + img_hsh[i + p][j] - t2 * img_hsh[i][j];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}