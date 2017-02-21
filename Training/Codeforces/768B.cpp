// written at 09:04 on 21 Feb 2017 
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
const int MAX_N = 1e5 + 10;

ll N, l, r;

int dfs(ll N, ll l, ll r) {
	if (l > r) return 0;
	if (N == 1) return 1;
	if (N == 0) return 0;
	ll mid = 1ll << (64 - __builtin_clzll(N / 2ll));
	ll res = 0;
	return dfs(N / 2, l, min(r, mid - 1)) + dfs(N / 2, max(l, mid + 1) - mid, r - mid)
		+ ((N % 2 && l <= mid && mid <= r)? 1ll : 0ll);
}

int main(int argc, char const *argv[])
{	
	while(cin >> N >> l >> r)
		cout << dfs(N, l, r) << endl;
	return 0;
}