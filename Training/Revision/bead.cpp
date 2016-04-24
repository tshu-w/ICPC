#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
const int maxn = 105;
int main(int argc, char const *argv[])
{
	int n, m, graph[maxn][maxn], a[maxn], b[maxn], ans = 0;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(graph, 0, sizeof(graph));

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		graph[y][x] = 1;
	}
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j) if (i != j)
				for (int k = 1; k <= n; ++k) if (i != k && j != k) {
					if (graph[i][j] && graph[j][k]) {
						graph[i][k] = 1;
					}
					if (graph[j][i] && graph[k][j]) {
						graph[k][i] = 1;
					}
				}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) if (i != j) {
				if (graph[i][j]) 
					a[i]++;
				if (graph[j][i])
					b[i]++;
			}
	for (int i = 1; i <= n; ++i)
		if (a[i] >= (n + 1) / 2 || b[i] >= (n + 1) / 2) 
			ans++;

	cout << ans << endl;
	return 0;
}