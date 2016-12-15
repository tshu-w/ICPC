#include <bits/stdc++.h>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int> Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 100 + 5;
const int MAX_P = 10 + 5;
const int MOD = 10007;

template <typename T>
inline T sqr(T a) { return a * a;};
int t, tt = 0, n, k, x, m, p, dp[MAX_N][200000], indx[3];
bool flag[MAX_N];

int encode(int *a, int n) {
	int res = 0;
	for (int i = 0; i < n; ++i)
		res = res * 3 + a[i];
	return res;
}
void decode(int *a, int res, int n) {
	for (int i = n - 1; i >= 0; --i, res /= 3)
		a[i] = res % 3;  
}
void add(int &a, int b) {
	a = (a + b) % MOD;
}
int main(int argc, char const *argv[])
{
	cin >> t;
	while (t--) {
		memset(flag, false, sizeof flag);
		memset(dp, 0, sizeof dp);
		cin >> n >> p;
		indx[0] = 1; indx[1] = p; indx[2] = m = p + 2;
		cin >> k;
		for (int i = 0; i < k; ++i)
			cin >> x, flag[x] = true;

		int nxt[MAX_P], cur[MAX_P], c;
		for (int i = 0; i < m; ++i) 
			cur[i] = 2;
		c = encode(cur, m);
		dp[0][c] = 1;

		for (int i = 0; i < n; ++i) 
			for (int j = 0; j <= c; ++j) if (dp[i][j]) {
				decode(cur, j, m);
				for (int k = m - 1; k >= 0; --k)
					nxt[k + 1] = cur[k];
				nxt[0] = 0;

				if (flag[i + 1]) {
					nxt[0] = 2;
					if (nxt[m] == 2) 
						add(dp[i + 1][encode(nxt, m)], dp[i][j]);
					continue;
				}

				if (nxt[m] == 2) 
					add(dp[i + 1][encode(nxt, m)], dp[i][j]);

				nxt[0] = 1;
				for (int k = 0; k < 3; ++k) {
					int &u = nxt[indx[k]];
					if (u < 2) {
						++u;
						if (nxt[m] == 2)
							add(dp[i + 1][encode(nxt, m)], dp[i][j]);
						--u;
					}
				}

				nxt[0] = 2;
				for (int k = 0; k < 3; ++k) 
					for (int h = k + 1; h < 3; ++h) {
						int &u = nxt[indx[k]];
						int &v = nxt[indx[h]];
						if (u < 2 && v < 2) {
							++u; ++v;
							if (nxt[m] == 2)
								add(dp[i + 1][encode(nxt, m)], dp[i][j]);
							--u; --v;
						}
					}
			}

		cout << "Case #" << ++tt << ": " << dp[n][c] << endl;
	}
	return 0;
}