#include <bits/stdc++.h>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);

const int INF = INT_MAX;
const int MAX_N = 200;
const int MAX_P = 50000;

int main(int argc, char const *argv[])
{
	int T, n, m, p, t[MAX_N], u[MAX_N], v[MAX_N], x[MAX_N], y[MAX_N], z[MAX_N], minSize, cost;
	int f[50000 + 5];
	cin >> T;
	while (T--) {
		cin >> n >> m >> p;
		for (int i = 0; i < n; ++i)
			cin >> t[i] >> u[i] >> v[i];
		for (int i = 0; i < m; ++i)
			cin >> x[i] >> y[i] >> z[i];

		fill(f, f + MAX_P + 1, INF / 3);f[0] = 0;minSize = INF;

		for (int i = 0; i < n; ++i) {
			int k;
			for (k = 1 << 0; k <= v[i] && t[i] * k <= MAX_P; v[i] -= k, k <<= 1) {
				for (int j = MAX_P; j >= t[i] * k; --j)
					f[j] = min(f[j], f[j - t[i] * k] + u[i] * k);
			}
			k = v[i];
			if (k > 0 && t[i] * k <= MAX_P) {
				for (int j = MAX_P; j >= t[i] * k; --j) 
					f[j] = min(f[j], f[j - t[i] * k] + u[i] * k);
			}
		}
		for (int i = p; i <= MAX_P; ++i)
			minSize = min(minSize, f[i]);

		fill(f, f + MAX_P + 1, 0);

		for (int i = 0; i < m; ++i) {
			int k;
			for (k = 1 << 0; k <= z[i] && y[i] * k <= MAX_P; z[i] -= k, k <<= 1) {
				for (int j = MAX_P; j >= y[i] * k; --j)
					f[j] = max(f[j], f[j - y[i] * k] + x[i] * k);
			}
			k = z[i];
			if (k > 0 && y[i] * k <= MAX_P) {
				for (int j = MAX_P; j >= y[i] * k; --j)
					f[j] = max(f[j], f[j - y[i] * k] + x[i] * k);
			}
		}
		
		if (f[MAX_P] < minSize) 
			cout << "TAT" << endl;
		else 
			cout << (cost = (int)(lower_bound(f, f + MAX_P + 1, minSize) - f)) << endl;
	}
	return 0;
}