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
int f[maxn];

struct edge
{
	int dis, u, v;
}g[maxn];

int find(int x) {
	return (f[x] == x)? x : f[x] = find(f[x]);
}
bool cmp(struct edge a, struct edge b) {
	return a.dis < b.dis;
}
int main(int argc, char const *argv[])
{
	int n, m = 0, min[maxn], total = 0, w;
	cin >> n;
	for (int i = 1; i <= n * n; ++i)
		f[i] = i;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) if (cin >> w && w){
			g[++m].dis = w;
			g[m].u = i;
			g[m].v = j;
 		}
	sort(g + 1, g + m + 1, cmp);
	int k = 1;
	for (int i = 1; i < m - 1 && k < n; ++i) if (g[i].dis != 0) {
		if (find(g[i].u) != find(g[i].v)) {
			f[find(g[i].u)] = find(g[i].v);
			k++;
			total += g[i].dis;
		}
	}
	cout << total << endl;
	return 0;
}