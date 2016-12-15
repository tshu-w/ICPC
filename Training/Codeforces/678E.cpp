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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 20;

template <typename T>
inline T sqr(T a) { return a * a;};

int N;
double ans, P[MAX_N][MAX_N], dp[1 << MAX_N][MAX_N];

int main(int argc, char const *argv[])
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> P[i][j];
	dp[1][0] = 1.;
	for (int i = 1; i < 1 << N; ++i)
		for (int j = 0; j < N; ++j)
			if (i >> j & 1)
				for (int k = 0; k < N; ++k)
					if (j != k && i >> k & 1)
						dp[i][j] = max(dp[i][j], dp[i - (1 << j)][k] * P[k][j] + dp[i - (1 << k)][j] * P[j][k]);
	for (int i = 0; i < N; ++i)
		ans = max(ans, dp[(1 << N) - 1][i]);
	printf("%.10f\n", ans);
	return 0;
}