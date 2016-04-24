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

const int maxn = 205;
int f[maxn * maxn];

int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
};
int main(int argc, char const *argv[])
{
	int n, x, y, xx, yy, m;
	char ch;
	cin >> n >> m;
	for (int i = 1; i <= n * n; ++i)
		f[i] = i;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y >> ch;
		if (ch == 'D') {
			xx = x + 1;
			yy = y;
		}
		else if (ch == 'R') {
			xx = x;
			yy = y + 1;
		}
		int fa, fb;
		fa = find(x * n + y);
		fb = find(xx * n + yy);
		if (fa == fb) {
			cout << i << endl;
			return 0;
		}
		else 
			f[fa] = fb;
	}
	cout << "draw" << endl;
	return 0;
}