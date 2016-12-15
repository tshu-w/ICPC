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
const int MAX_N = 1000 + 10;
const int MAX_M = 40;

template <typename T>
inline T sqr(T a) { return a * a;};

int T, W, dp[MAX_M], ans = 0;

int main(int argc, char const *argv[])
{
	cin >> T >> W;
	memset(dp, 0, sizeof dp);
	for (int i = 0, a; i < T; ++i) {
		cin >> a;
		for (int j = W; j >= 0; --j)
			if (j % 2 == a - 1) ++dp[j];
			else if (j) dp[j] = max(dp[j], dp[j - 1] + 1);
	}
	for (int i = 0; i <= W; ++i)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}