#include <stdio.h>

int n, m, k;
int a[25];
int go(int p, int d, int t) {
    while (t--) {
        do { p = (p + d + n -1) % n + 1;} while (!a[p]);
    }
    return p;
}
int main(int argc, const char * argv[]) {
    while (scanf("%d%d%d", &n, &k, &m) == 3 && n) {
        for (int i = 1;i <= n; i ++) a[i] = i;
        int left = n;
        int p1 = n; int p2 = 1;
        while (left) {
            p1 = go(p1,  1, k);
            p2 = go(p2, -1, m);
            a[p1] = 0;
            a[p2] = 0;
            printf("%3d", p1);
            left --;
            if (p1 != p2) {
                printf("%3d", p2);
                left--;
            }
            if (left) printf(",");
        }
        putchar('\n');
    }
    return 0;
}