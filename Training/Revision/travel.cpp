#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>
#include <sstream>

using namespace std;
const int maxn = 505, maxm = 105;

int main(void) {
    int n, m, way[maxn][maxn], dis[maxn], route[maxn];
    bool vis[maxn];
    cin >> m >> n;
    memset(vis, 0, sizeof(vis));
    memset(way, 0, sizeof(way));
    for (int i = 1; i <= n; ++i) {
        dis[i] = INT_MAX / 3;
    }
    string line;
    getline(cin, line);
    for (int i = 1; i <= m; ++i) {
        //cout << i << endl;
        int x, count(0);
        getline(cin, line);
        stringstream ss(line);
        while (ss >> x) {
            route[++count] = x;
            //cout << x << endl;
        }
        for (int j = 1; j <= count; ++j)
            for (int k = j + 1; k <= count; ++k) {
                int u, v;
                u = route[j];
                v = route[k];
                //cout << u << " " << v << endl;
                way[u][0]++;
                way[u][way[u][0]] = v;
                way[v][0]++;
                way[v][way[v][0]] = u;
            }
    }
    dis[1] = 0;
    for (int i = 1; i <= n; ++i) {
        int u = 0, mmin = INT_MAX;
        for (int j = 1; j <= n; ++j)
            if (mmin > dis[j] && !vis[j]) {
                u = j;
                mmin = dis[j];
            }
        vis[u] = true;
        for (int  j = 1; j <= way[u][0]; ++j) {
            int v = way[u][j];
            dis[v] = min(dis[u] + 1,dis[v]);
        };
    }
    cout << dis[n] << endl;
    return 0;
}