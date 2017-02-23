// written at 15:16 on 23 Feb 2017
// Judge not available now
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
	#define DEBUG(...) printf(__VA_ARGS__)
#else
	#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;
typedef pair<Pii, Pii > Tii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;
const int MOD = 1e9 + 7;

inline int add(int a, int b) { return (a + b) % MOD;}
inline int mul(int a, int b) { return 1ll * a * b % MOD;}
inline int del(int a, int b) { return (a - b + MOD) % MOD;}

int N, M, K, dp[MAX_N], a, b, c, d;
int fact[2 * MAX_N];
vector<Tii> v;

void init_fact() {
	fact[0] = 1;
	rep(i, 1, 2 * MAX_N) fact[i] = mul(i, fact[i - 1]);
}
int inv(int x) {
	return x == 1? 1 : (MOD - mul((MOD / x), inv(MOD % x)) % MOD) % MOD;
}
int C(int n, int k) {
	return mul(mul(fact[n], inv(fact[k])), inv(fact[n - k]));
}
int cal(Pii p1, Pii p2) {
	if (p2.first < p1.first || p2.second < p1.second) return 0;
	return C(p2.first + p2.second - p1.first - p1.second, p2.first - p1.first);
}
void solve() {
	memset(dp, 0, sizeof dp);
	sort(v.begin(), v.end());
	v.push_back(Tii(Pii(N, M), Pii(N + 1, M + 1)));
	rep(i, 0, K + 1) {
		dp[i] = C(v[i].first.first + v[i].first.second, v[i].first.first);
		rep(j, 0, i) 
			dp[i] = add(dp[i], mul(dp[j], del(cal(v[j].second, v[i].first), cal(v[j].first, v[i].first))));
	}
	printf("%d\n", dp[K]);
}
int main(int argc, char const *argv[])
{
	init_fact();
	while (scanf("%d%d%d", &N, &M, &K), N + M + K) {
		--N, --M;
		v.clear();
		rep(i, 0, K) {
			scanf("%d%d%d%d", &a, &b, &c, &d);
			v.push_back(Tii(Pii(a - 1, b - 1), Pii(c - 1, d - 1)));
		}
		solve();
	}
	return 0;
}