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
const int MAX_N = 200000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, m, k, t, A[MAX_N], sum[MAX_N];

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", A + i);
			sum[i + 1] = sum[i] + ((A[i] >= m)? 1 : 0);
		}
		ll ans = 0;
		int s = 0, t = 1;
		for (;;) {
			while (t <= n && sum[t] - sum[s] < k) ++t;
			if (sum[t] - sum[s] < k) break;
			ans += n - t + 1;
			++s;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}