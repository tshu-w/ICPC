#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cfloat>
#include <queue>

using namespace std;

const int maxn = 105;
typedef struct Point
{
	int x, y;
	double dis(struct Point v) {
		return sqrt(pow(x - v.x, 2) + pow(y - v.y, 2));
	}
}POINT;
int main(int argc, char const *argv[])
{
	POINT pnt[maxn];
	double w[maxn][maxn], dis[maxn];
	int adj[maxn][maxn];
	bool vis[maxn];
	queue<int> que;
	int s, t, m, n;

	memset(adj, 0, sizeof(adj));
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> pnt[i].x >> pnt[i].y;
	}
	cin >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			w[i][j] = DBL_MAX / 3;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u][0]++;
		adj[u][adj[u][0]] = v;
		adj[v][0]++;
		adj[v][adj[v][0]] = u;
		w[u][v] = w[v][u] = pnt[u].dis(pnt[v]);
		// cout <<  w[u][v] << endl;
	}
	cin >> s >> t;
	for (int i = 1; i <= n; ++i) {
		dis[i] = (i != s)? DBL_MAX / 3 : 0;
	}
	memset(vis, 0, sizeof(vis));
	vis[s] = true;
	que.push(s);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		vis[u] = false;
		for (int i = 1; i <= adj[u][0]; ++i) {
			int v = adj[u][i];
			if (dis[v] > dis[u] + w[u][v]) {
				dis[v] = dis[u] + w[u][v];
				if (!vis[v]) {
					que.push(v);
					vis[v] = true;
				}
			}
		}
	}
	cout << dis[t] << endl;
	return 0;
}