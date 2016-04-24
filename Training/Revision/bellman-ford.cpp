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
const int maxm = maxn * maxn;
typedef struct Point
{
	int x, y;
	double dis(struct Point v) {
		return sqrt(pow(x - v.x, 2) + pow(y - v.y, 2));
	}
}POINT;
typedef struct Edge
{
	int u, v;
	double dis;
}EDGE;
int main(int argc, char const *argv[])
{
	POINT pnt[maxn];
	EDGE w[maxm];
	double dis[maxn];
	// bool vis[maxn];
	int s, t, m, n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> pnt[i].x >> pnt[i].y;
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		w[i].dis = pnt[u].dis(pnt[v]);
		w[i].u = u;
		w[i].v = v;
	}
	cin >> s >> t;
	for (int i = 1; i <= n; ++i) {
		dis[i] = (i != s)? DBL_MAX : 0;
	}
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) {
			int u, v;
			u = w[j].u;
			v = w[j].v;
			dis[v] = min(dis[u] + w[j].dis, dis[v]);
			dis[u] = min(dis[v] + w[j].dis, dis[u]);
		}
	cout << dis[t] << endl;
	return 0;
}