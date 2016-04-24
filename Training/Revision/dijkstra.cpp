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
	bool vis[maxn];
	int s, t, m, n;
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
		w[u][v] = w[v][u] = pnt[u].dis(pnt[v]);
		// cout <<  w[u][v] << endl;
	}
	cin >> s >> t;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; ++i) {
		dis[i] = (i != s)? w[s][i] : 0;
	}
	for (int i = 1; i <= n; ++i) {
		double mmin = DBL_MAX / 3;
		int k = 0;
		for (int j = 1; j <= n; ++j)
			if (!vis[j] && dis[j] < mmin) {
				mmin = dis[j];
				k = j;
			}
		if (!k) break;
		vis[k] = 1;
		for (int j = 1; j <= n; ++j)
			dis[j] = min(dis[k] + w[k][j],dis[j]);
	}
	cout << dis[t] << endl;
	return 0;
}