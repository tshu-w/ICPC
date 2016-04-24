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
	int n, min[maxn], g[maxn][maxn], total = 0;
	bool visit[maxn];
	cin >> n;
	for (int i = 1; i <= n; ++i)
		min[i] = INT_MAX / 3;
	memset(visit, 0 , sizeof(0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> g[i][j];
	min[1] = 1;
	for (int i = 1; i <= n; ++i) {
		int k = 0, mmin = INT_MAX;
		for (int j = 1; j <= n; ++j)
			if (!visit[j] && min[j] < mmin) {
				mmin = min[j];
				k = j;
			}
		visit[k] = true;
		total += min[k];
		for (int j = 1; j <= n; ++j)
			min[j] = min(min[k] + g[k][j], min[j]);
	}
	return 0;
}