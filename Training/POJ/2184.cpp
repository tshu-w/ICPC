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
typedef pair<int, int> Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 100;
const int gap = 1e5;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, S, F, dp[2 * gap + 10];

int main(int argc, char const *argv[])
{
	while (~scanf("%d", &N)) {
		for (int i = 0; i <= 2 * gap; ++i)
			dp[i] = -INF;
		dp[gap] = 0;

		for (int i = 0; i < N; ++i) {
			scanf("%d%d", &S, &F);
			if (S > 0) {
				for (int j = 2 * gap; j >= S; --j)
					if (dp[j - S] != -INF)
						dp[j] = max(dp[j], dp[j - S] + F);
			} else {
				for (int j = S; j <= 2 * gap + S; ++j)
					if (dp[j - S] != -INF)
						dp[j] = max(dp[j], dp[j - S] + F);
			}
		}
		int ans = 0;
		for (int i = gap; i <= 2 * gap; ++i)
			if (dp[i] >= 0)
				ans = max(ans, dp[i] + i - gap);
		printf("%d\n", ans);
	}
    return 0;
}