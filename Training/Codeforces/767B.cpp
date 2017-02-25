// written at 16:57 on 18 Feb 2017 
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
	#define DEBUG(...) printf(__VA_ARGS__)
#else
	#define DEBUG(...)
#endif
#define filename "B"
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
typedef pair<ll, ll > Pll;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;

ll ts, tf, t, T[MAX_N], ans, imin = LLINF;
Pll sf[MAX_N];
int N;

int main(int argc, char const *argv[])
{
	scanf("%I64d%I64d%I64d", &ts, &tf, &t);
	scanf("%d", &N);
	rep(i, 0, N) scanf("%I64d", T + i);
	sort(T, T + N);
	ll s = 0, f = ts;
	rep(i, 0, N) {
		if (f - T[i] + 1 < imin && T[i] - 1 >= 0) {
			imin = f - T[i] + 1;
			ans = T[i] - 1;
		}
		s = T[i]; if (s > f) break;
		f = max(s, f) + t;
		if ((i == N || T[i + 1] != T[i]) && f - T[i] < imin) {
			imin = max(ts, f) - T[i];
			ans = T[i];
		}
		if (f + t > tf) break;
	}
	if (f + t <= tf) ans = f;
	printf("%I64d\n", ans);
	return 0;
}