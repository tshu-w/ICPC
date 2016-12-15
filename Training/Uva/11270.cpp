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
const int INF = INT_MAX;
const int MAX_M = 20;

template <typename T>
inline T sqr(T a) { return a * a;};

ll dp[2][1 << MAX_M];
int N, M;

void solve() {
	ll *crt = dp[0], *nxt = dp[1];
	crt[0] = 1;
	for (int i = N - 1; i >= 0; --i) {
		for (int j = M - 1; j >= 0; --j) {
			for (int used = 0;  used < 1 << M; ++used) {
				if (used >> j & 1) {
					nxt[used] = crt[used & ~(1 << j)];
				} else {
					ll res = 0;
					if (j + 1 < M && !(used >> (j + 1) & 1)) {
						res += crt[used | 1 << (j + 1)];
					}
					if (i + 1 < N) {
						res += crt[used | 1 << j];
					}
					nxt[used] = res;
				}
			}
			swap(crt, nxt);
		}
	}
	printf("%lld\n", crt[0]);
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d%d", &N, &M)) {
		if (N < M) swap(N, M);
		solve();
	}	
	return 0;
}