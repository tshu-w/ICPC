#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>

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
	double dis[maxn][maxn];
	int s, t, m, n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> pnt[i].x >> pnt[i].y;
	}
	cin >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dis[i][j] = INT_MAX / 3;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		dis[u][v] = dis[v][u] = pnt[u].dis(pnt[v]);
		// cout <<  w[u][v] << endl;
	}
	cin >> s >> t;
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) 
				dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
	cout << dis[s][t] << endl;
	return 0;
}