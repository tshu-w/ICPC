#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pii;
const int maxn = 1e3 + 10;

int n, a, b, g[maxn][maxn];

int main() {
    scanf("%d%d%d", &n, &a, &b);
    if (a != 1 && b != 1) {
        printf("NO\n");
        return 0;
    }
    if (a == 1 && b == 1) {
        if (n == 2 || n == 3) {
            printf("NO\n");
            return 0;
        }
        printf("YES\n");
        for (int i = 0; i < n - 1; i++)
            g[i][i+1] = g[i+1][i] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%d", g[i][j]);
            printf("\n");
        }
        return 0;
    }
    printf("YES\n");
    int m = max(a, b);
    for (int i = m; i < n; i++)
        g[0][i] = g[i][0] = 1;
    if (a != m) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) 
                if (i != j)
                    g[i][j] = 1 ^ g[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d", g[i][j]);
        printf("\n");
    }
    return 0;
}