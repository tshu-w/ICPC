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
const int maxn = 100;

int main(void) {
    int n, w[maxn][maxn], dis[maxn], edge[maxn][maxn], s;
    bool vis[maxn];
    queue<int> que;
    cin >> n >> s;
    string word;
    memset(edge, 0, sizeof(edge));
    memset(edge, 0, sizeof(edge));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> word;
            if (word[0] != '-') {
                w[i][j] = stoi(word, nullptr, 0);
                //cout << i << " " << j << " " << w[i][j] << endl;
                edge[i][0]++;
                edge[i][edge[i][0]] = j;
            }
    }
    for (int i = 1; i <= n; ++i)
        dis[i] = (i != s)? INT_MAX / 3 : 0;
    que.push(s);
    vis[s] = true;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = 1; i <= edge[u][0]; ++i) {
            int v = edge[u][i];
            if(dis[v] > dis[u] + w[u][v]) {
                dis[v] = dis[u] + w[u][v];
                if (!vis[v]) {
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) 
        if (i != s)
            cout << dis[i] << endl;
    return 0;
}