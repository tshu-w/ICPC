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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 10000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int K, R, N, L[MAX_N], T[MAX_N], W[MAX_N], H[MAX_N];
ll area;

bool C(int x) {
	ll res = 0;
	for (int i = 0; i < N; ++i)
		if (L[i] + W[i] <= x)
			res += 1ll * W[i] * H[i];
		else if (x > L[i]) res += 1ll * H[i] * (x - L[i]);
	// cout << x << ": " << res << endl;
	if (res < area - res)
		return false;
	return true;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &K);
	while (K--) {
		scanf("%d", &R);
		scanf("%d", &N);
		area = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d%d%d%d", L + i, T + i, W + i, H + i);
			H[i] = min(T[i], H[i]);
			W[i] = min(R - L[i], W[i]);
			area += 1ll * W[i] * H[i];
		}
		int lb = -1, ub = R;
		while (ub - lb > 1) {
			int mid = (ub - lb) / 2 + lb;
			if (C(mid)) ub = mid;
			else lb = mid;
		}
		int ans = -1;
		for (int i = 0; i < N; ++i)
			if (L[i] <= ub && ub < L[i] + W[i] && H[i])
				ans = ub;
		if (ans == -1) {
			ans = R;
			for (int i = 0; i < N; ++i)
				if (L[i] > ub && H[i])
					ans = min(L[i], ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}