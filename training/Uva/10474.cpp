#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int main(int argc, char const *argv[])
{
    int n, q, a[maxn], cases(0);
    while (scanf("%d%d", &n, &q) && n) {
        printf("CASE# %d:\n", ++cases);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        sort(a, a + n);
        while (q--) {
            int x;
            scanf("%d", &x);
            int p = lower_bound(a, a + n, x) - a;
            if (a[p] == x) 
                printf("%d found at %d\n", x, p + 1);
            else 
                printf("%d not found\n", x);
        }
    }
    return 0;
}