#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
	#define DEBUG(...) printf(__VA_ARGS__)
#else
	#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const ll INF = (ll)INT_MAX * 1000;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int t;
ll N, M;

ll f(ll i, ll j) {
	return i * i + 100000 * i + j * j - 100000 * j + i * j;
}

bool C(ll k) {
	ll cnt = 0;
	for (int j = 1; j <= N; ++j) {
		int lb = 0, ub = N + 1;
		while (ub - lb > 1) {
			int i = (ub - lb) / 2 + lb;
			if (f(i, j) < k) lb = i;
			else ub = i;
		}
		cnt += lb;
	}
	return cnt < M;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &N, &M);
		ll lb = -INF, ub = INF;
		while (ub - lb > 1) {
			ll mid = (ub - lb) / 2 + lb;
			if (C(mid)) lb = mid;
			else ub = mid;
		}
		printf("%lld\n", lb);
	}	
	return 0;
}