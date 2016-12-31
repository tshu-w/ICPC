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

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1000 + 10;

int N, M, W, w[MAX_N], b[MAX_N], x, y, dp[MAX_N], K, ans;
int par[MAX_N], rnk[MAX_N], flag[MAX_N];
vector<Pii> v[MAX_N];

void init(int n) {
	for (int i = 0; i < n; ++i)
		par[i] = i, rnk[i] = 0;
}
int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}
bool same(int x, int y) {
	return find(x) == find(y);
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) {
		par[x] = y;
	} else {
		par[y] = x;
		if (rnk[x] == rnk[y]) ++rnk[x];
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &N, &M, &W);
	rep(i, 0, N) scanf("%d", w + i);
	rep(i, 0, N) scanf("%d", b + i);
	init(N);
	rep(i, 0, M) {
		scanf("%d%d", &x, &y);
		unite(--x, --y);
	}
	memset(flag, -1, sizeof flag);K = 0;
	rep(i, 0, N) {
		int fa = find(i);
		if (~flag[fa]) v[flag[fa]].push_back(Pii(w[i], b[i]));
		else v[K].push_back(Pii(w[i], b[i])), flag[fa] = K++;
	}
	rep(k, 0, K) {
		int totw = 0, totb = 0;
		rep(i, 0, v[k].size()) totw += v[k][i].first, totb += v[k][i].second;
		v[k].push_back(Pii(totw, totb));
	}
	rep(k, 0, K) {
		irep(j, W + 1, 0) rep(i, 0, v[k].size()) if (j >= v[k][i].first)
			dp[j] = max(dp[j], dp[j - v[k][i].first] + v[k][i].second);
	}
	ans = 0;
	irep(i, W + 1, 0) ans = max(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}