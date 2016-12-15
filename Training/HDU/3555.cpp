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
const int MAX_N = 25;

template <typename T>
inline T sqr(T a) { return a * a;};

ll N, dp[MAX_N][3];
int t;

void init() {
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		dp[i][0] = dp[i - 1][0] * 10 - dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][1];
	}
}

ll count(ll N) {
	int len = 0, a[MAX_N];
	ll ans = 0;
	bool flag = false;
	
	while (N) {
		a[++len] = N % 10;
		N /= 10;
	}

	a[len + 1] = 0;

	for (int i = len; i; --i) {
		ans += a[i] * dp[i - 1][2];
		if (flag) ans += a[i] * dp[i - 1][0];
		else if (a[i] > 4) ans += dp[i - 1][1];
		if (a[i + 1] == 4 && a[i] == 9) flag = true;
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	init();
	scanf("%d", &t);
	while (t--) {
		cin >> N;
		cout << count(N + 1) << endl;
	}
	return 0;
}