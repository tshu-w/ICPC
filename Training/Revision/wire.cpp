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

int main(int argc, char const *argv[])
{
	int n, dis[maxn], g[maxn][maxn], total = 0;
	bool visit[maxn];
	cin >> n;
	for (int i = 1; i <= n; ++i)
		dis[i] = INT_MAX / 3;
	memset(visit, 0 , sizeof(0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> g[i][j];
	dis[1] = 0;
	for (int i = 1; i <= n; ++i) {
		int k = 0, mmin = INT_MAX;
		for (int j = 1; j <= n; ++j)
			if (!visit[j] && dis[j] < mmin) {
				mmin = dis[j];
				k = j;
			}
		visit[k] = true;
		total += dis[k];
		for (int j = 1; j <= n; ++j) if (!visit[j])
			dis[j] = min(g[k][j], dis[j]);
	}
	cout << total << endl;
	return 0;
}