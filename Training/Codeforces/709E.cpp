// written at 09:22 on 23 Feb 2017 
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
const ll LLINF = LLONG_MAX;
const int MAX_N = 4e5 + 10;

int N, ans[MAX_N], sz[MAX_N], ms[MAX_N][2], mv[MAX_N][2];
vector<int> G[MAX_N];

void dfs(int v, int p) {
	sz[v] = 1;
	for (auto u : G[v]) if (u != p) {
		dfs(u, v); sz[v] += sz[u];
		int t = sz[u] <= N / 2? sz[u] : ms[u][0];
		if (t > ms[v][0]) mv[v][1] = mv[v][0], mv[v][0] = u, ms[v][1] = ms[v][0], ms[v][0] = t;
		else if (t > ms[v][1]) mv[v][1] = u, ms[v][1] = t;
	}
}
void dfs1(int v, int p, int lst) {
	if (N - sz[v] - lst <= N / 2) ans[v] = 1;
	for (auto u : G[v]) if (u != p) {
		if (sz[u] - ms[v][0] > N / 2) ans[v] = 0;
		dfs1(u, v, N - sz[u] <= N / 2? N - sz[u] : max(lst, ms[v][mv[v][0] == u]));
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	for (int i = 1, u, v; i < N; ++i)
		scanf("%d%d", &u, &v), G[u].push_back(v), G[v].push_back(u);
	dfs(1, 0), dfs1(1, 0, 0);
	rep(i, 1, N + 1) printf("%d ", ans[i]); printf("\n");
	return 0;
}