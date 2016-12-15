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
#define irep(i, j, k) for (int i = j; i > k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const double INF = 100 * 30 + 5;
const int MAX_N = 13;
const int MAX_M = 33;

int N, M, P, a, b, t[MAX_N], d[MAX_M][MAX_M];
double dp[1 << MAX_N][MAX_M];

void solve() {
	for (int i = 0; i < 1 << N; ++i)
		fill(dp[i], dp[i] + M, INF);
	dp[(1 << N) - 1][a] = 0;
	double res = INF;
	for (int S = (1 << N) - 1; S >= 0; --S) {
		res = min(res, dp[S][b]);
			for (int i = 0; i < N; ++i) if (S & 1 << i)
				for (int v = 0; v < M; ++v)
					for (int u = 0; u < M; ++u) if (d[v][u] >= 0) 
						dp[S & ~(1 << i)][u] = min(dp[S & ~(1 << i)][u], dp[S][v] + (double)d[v][u] / t[i]);
	}
	if (res == INF)
		printf("Impossible\n");
	else printf("%.3f\n", res);
}
int main(int argc, char const *argv[])
{
	while (scanf("%d%d%d%d%d", &N, &M, &P, &a, &b) && N + M + P + a + b) {
		--a; --b;
		memset(d, -1, sizeof d);
		rep(i, 0, N) scanf("%d", t + i);
		rep(i, 0, P) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c); --u; --v;
			d[u][v] = d[v][u] = c;
		}
		solve();
	}	
	return 0;
}