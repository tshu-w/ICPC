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

const int maxn = 20000, maxm = 1000000;

int ufs[maxn];

int find(int x) {
	if (ufs[x] != x)
		ufs[x] = find(ufs[x]);
	return ufs[x];
};

int main(int argc, char const *argv[])
{
	int n, m, q;

	cin >> n >> m >> q;

	for (int i = 1; i <= n; ++i)
		ufs[i] = i;

	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b)) {
			int fa = find(a);
			int fb = find(b);
			if (fa != fb)
				ufs[fa] = fb;
		}
	}
	for (int i = 1; i <= q; ++i) {
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}