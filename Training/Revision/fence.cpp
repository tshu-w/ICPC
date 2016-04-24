#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algori>

using namespace std;

const int maxn = 505;
int f, graph[maxn][maxn], indgr[maxn], n = 1;
bool flag[maxn];

int dfs(int p) {
	for (int i = 1; i <= n; ++i)
		if (graph[p][i]) {
			cout << i << endl;
			graph[p][i] = 0;
			graph[i][p] = 0;
			dfs(i);
			break;
		}
	return 0;
}
int main(int argc, char const *argv[])
{
	cin >> f;
	memset(graph, 0, sizeof(graph));
	memset(flag, 0, sizeof(flag));
	memset(indgr, 0, sizeof(indgr));
	for (int i = 0; i < f; ++i) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
		indgr[x]++;
		indgr[y]++;
		if (x > n)
			n = x;
		if (y > n)
			n = y;
	}
	int b = 1;
	for (int i = 1; i <= n; ++i)
		if (indgr[i] % 2) {
			b = i;
			break;
		}
	flag[b] = 1;
	cout << b << endl;
	dfs(b);
	return 0;
}