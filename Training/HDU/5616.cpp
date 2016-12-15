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
const int MAX_N = 25;
const int MAX_W = 105;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, M, T, W[MAX_N], sum;
bool dp[MAX_N][MAX_N * MAX_W * 2];
int main(int argc, char const *argv[])
{
	cin >> T;
	while (T--) {
		scanf("%d", &N);
		sum = 0;
		for (int i = 1; i <= N; ++i) {
			scanf("%d", W + i);
			sum += W[i];
		}
		memset(dp, false, sizeof dp);
		dp[0][100] = true;
		for (int i = 1; i <= N; ++i)
			for (int j = 100; j <= sum + 100; ++j) {
				dp[i][j] |= dp[i - 1][j]; 
				dp[i][j] |= dp[i - 1][j - W[i]];
				if (j + W[i] <= sum + 100)
					dp[i][j] |= dp[i - 1][j + W[i]];
			}
		scanf("%d", &M);
		for (int i = 0, q; i < M; ++i) {
			scanf("%d", &q);
			printf("%s\n", dp[N][q + 100]? "YES" : "NO");
		}
	}	
	return 0;
}