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

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e6 + 10;

int N, r, q;
ll dp[MAX_N];

ll dfs(int k) {
	if (k <= 1) return 0;
	if (dp[k]) return dp[k];
	int j = 1;
	ll ans = LLONG_MAX;
	do {
		ans = min(ans, dfs((k + j) / (j + 1)) + (ll)j * q + r);
		if (j < k - 1)
			j = (k + j) / ((k + j) / (j + 1));
		else break;
	} while (j <= k);
	return dp[k] = ans;
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d%d%d", &N, &r, &q)) {
		memset(dp, 0, sizeof dp);
		printf("%lld\n", dfs(N));
	}	
	return 0;
}