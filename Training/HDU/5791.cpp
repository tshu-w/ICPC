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
const int MAX_N = 1000 + 10;
const ll MOD = 1000000007;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, M, A[MAX_N], B[MAX_N];
ll dp[MAX_N][MAX_N];

int main(int argc, char const *argv[])
{
	while (~scanf("%d%d", &N, &M)) {
		for (int i = 0; i < N; ++i)
			// A[i] = i;
			scanf("%d", A + i);
		for (int j = 0; j < M; ++j)
			// B[j] = j;
			scanf("%d", B + j);
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				dp[i + 1][j + 1] = (dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + (A[i] == B[j] ? dp[i][j] + 1 : 0) + MOD) % MOD;
		// printf("%I64d\n", dp[N][M]);
		cout << dp[N][M] << endl;
	}
	return 0;
}