#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>

using namespace std;
const int maxn = 105;
int main() {
    int n, m, dis[maxn][maxn];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dis[i][j] = INT_MAX / 3;
    for (int i = 1; i <= m; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        dis[u][v] = dis[v][u] = k;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
    int ans = 0;
    for (int i = 2; i <= n; ++i)
    if (ans == INT_MAX / 3)
        ans = max(dis[1][i], ans);
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}