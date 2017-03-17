#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e3 + 10;
const ll MOD = 1000003;

int n, k, f[MAX_N], fa[MAX_N][MAX_N], fb[MAX_N][MAX_N];
ll ans, apd, inv[MAX_N];

void init_inverse() {
	inv[1] = 1;
	rep(i, 2, MAX_N) inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
}
void dp() {
	memset(f, 0, sizeof f); memset(fa, 0, sizeof fa); memset(fb, 0, sizeof fb);
	if (k >= n) k = n - 1, apd = 2;
	fa[1][1] = 1; fb[1][1] = 0;
	int suma = 1, sumb = 0;
	rep(i, 2, n + 1) {
		fa[i][1] = sumb; fb[i][1] = suma;
		swap(suma, sumb);
		rep(j, 2, k + 1) {
			fa[i][j] = fa[i - 1][j - 1];
			suma = (suma + fa[i][j]) % MOD;
			fb[i][j] = fb[i - 1][j - 1];
			sumb = (sumb + fb[i][j]) % MOD;
		}
	}	
	rep(i, 1, n + 1) rep(j, 1, k + 1) 
		f[i] = (f[i] + fb[i][j]) % MOD;
	rep(i, 1, n + 1) rep(j, 1, k + 1)
		fb[i][j + 1] = (fb[i][j + 1] + fb[i][j]) % MOD;
	rep(i, 1, n + 1) rep(j, 1, min(i, k) + 1)
		f[i] = (f[i] + fb[i - j][k - j]) % MOD;
}
int main(int argc, char const *argv[])
{
	init_inverse();
	while (scanf("%d%d", &n, &k), n + k) {
		ans = 0, apd = 0;
		dp();
		rep(i, 0, n)
			ans = (ans + 2 * f[__gcd(i, n)]) % MOD;
		ans = ans * inv[n] % MOD;
		printf("%lld\n", (ans + apd) % MOD);
	}
	return 0;
}