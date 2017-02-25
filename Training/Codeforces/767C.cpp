// written at 16:57 on 18 Feb 2017 
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
const int MAX_N = 1e6 + 10;

int N, T[MAX_N], sum, p, root;
vector<int> G[MAX_N], ans;

int dfs(int v) {
	int res = T[v];
	rep(i, 0, G[v].size())
		res += dfs(G[v][i]);
	if (res == sum / 3 && v != root) ans.push_back(v), res = 0;
	return res;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	rep(i, 1, N + 1) {
		scanf("%d%d", &p, T + i);
		if (p) G[p].push_back(i); else root = i;
		sum += T[i];
	}
	dfs(root);
	if (sum % 3 || ans.size() < 2) printf("-1\n");
	else printf("%d %d\n", ans[0], ans[1]);
	return 0;
}