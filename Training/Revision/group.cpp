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

int find(int x) {
	return (f[x] == x)? x : f[x] = find(f[x]);
}
int main(int argc, char const *argv[])
{
	int n, m, p, x, y, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= 2 * n; ++i)
		f[i] = i;
	for (int i = 1; i <= m; ++i) {
		cin >> p >> x >> y;
		if (p) {
			f[find(x)] = find(y + n);
			f[find(y)] = find(x + n);
		}
		else 
			f[find(x)] = find(y);
	}
	for (int i = 1; i <= n; ++i) 
		f[i] = find(i);
	sort(f + 1, f + n + 1);
	for (int i = 1; i <= n; ++i)
		if (f[i] != f[i - 1])
			ans++;
	cout << ans << endl;
	return 0;
}