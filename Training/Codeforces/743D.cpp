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
const ll INF = LLONG_MIN;
const int MAX_N = 2e5 + 10;

int N, u, v;
ll m[MAX_N], mm[MAX_N], A[MAX_N];
vector<int> G[MAX_N];

ll cnt(int v, int p) {
	ll res = A[v]; m[v] = INF, mm[v] = INF;
	for (int u : G[v])
		if (u != p) {
			ll tmp = cnt(u, v);
			res += tmp;
			tmp = max(tmp, m[u]);
			if (tmp > m[v]) {
				mm[v] = m[v];
				m[v] = tmp;
			} else if (tmp > mm[v]) mm[v] = tmp;
		}
	return res;
}
ll dfs(int v, int p) {
	ll ans = INF;
	for (int u : G[v])
		if (u != p) ans = max(ans, dfs(u, v));
	if (m[v] != INF && mm[v] != INF) ans = max(ans, m[v] + mm[v]);
	return ans;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	rep(i, 0, N) scanf("%lld", A + i);
	rep(i, 1, N) {
		scanf("%d%d", &u, &v); --u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cnt(0, -1);
	ll ans = dfs(0, -1);
	if (ans == INF) printf("Impossible\n");
	else cout << ans << endl;
	return 0;
}