#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <bitset>

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
const int MAX_N = 12;

int N, M;
ll dp[2][1 << MAX_N];

void solve() {
	ll *crt = dp[0], *nxt = dp[1];
	crt[0] = 1;
	irep(i, N, 0)
		irep(j, M, 0) {
			rep(used, 0, (1 << M))
				if (used >> j & 1)
					nxt[used] = crt[used & ~(1 << j)];
				else {
					nxt[used] = 0;
					if (j + 1 < M && !(used >> (j + 1) & 1))
						nxt[used] += crt[used | 1 << (j + 1)];
					if (i + 1 < N)
						nxt[used] += crt[used | 1 << j];
				}
			swap(crt, nxt);
		}
	printf("%lld\n", crt[0]);
}
int main(int argc, char const *argv[])
{
	while (~scanf("%d%d", &N, &M) && N + M) {
		if (N < M) swap(N, M);
		solve();
	}	
	return 0;
}