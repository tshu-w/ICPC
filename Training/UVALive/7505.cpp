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
const int MOD = 1e9 + 7;

int t, tt, N, K;
ll pw2[MAX_N], dp[MAX_N], sum[MAX_N];

void init() {
	pw2[0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		pw2[i] = (pw2[i - 1] * 2) % MOD;
		sum[i] = sum[i - 1] + i;
	}
}

ll get(int K) {
	for (int i = K; i; --i)
		if (2 * sum[i] < sum[K]) {
			return i;
		}
	return 0;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	init();
	while (t--) {
		scanf("%d%d", &N, &K);
		dp[K] = pw2[get(K)];
		ll tmp = dp[K];
		int j = K;
		for (int i = K + 1; i <= N; ++i) {
			while (2 * sum[j] < sum[i]) {
				tmp -= dp[j];
				if (tmp < 0) tmp += MOD;
				++j;
			}
			dp[i] = tmp % MOD; tmp = (tmp + dp[i]) % MOD;
		}
		printf("Case #%d: %lld\n", ++tt, dp[N] * 2 % MOD);
	}	
	return 0;
}