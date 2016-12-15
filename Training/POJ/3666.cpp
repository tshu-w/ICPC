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
const int MAX_N = 20000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, A[MAX_N], B[MAX_N], dp[2][MAX_N], ans;

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", A + i);
	memcpy(B, A, sizeof A);
	sort(B, B + N);
	for (int j = 0; j < N; ++j)
		dp[0 & 1][j] = abs(A[0] - B[j]);
	for (int i = 1; i < N; ++i) {
		int minpre = dp[(i - 1) & 1][0];
		for (int j = 0; j < N; ++j) {
			minpre = min(minpre, dp[(i - 1) & 1][j]);
			dp[i & 1][j] = minpre + abs(A[i] - B[j]);
		}
	}
	ans = *min_element(dp[(N - 1) & 1], dp[(N - 1) & 1] + N);
	sort(B, B + N, greater<int>());
	for (int j = 0; j < N; ++j)
		dp[0 & 1][j] = abs(A[0] - B[j]);
	for (int i = 1; i < N; ++i) {
		int minpre = dp[(i - 1) & 1][0];
		for (int j = 0; j < N; ++j) {
			minpre = min(minpre, dp[(i - 1) & 1][j]);
			dp[i & 1][j] = minpre + abs(A[i] - B[j]);
		}
	}	
	ans = min(ans, *min_element(dp[(N - 1) & 1], dp[(N - 1) & 1] + N));
	printf("%d\n", ans);
	return 0;
}