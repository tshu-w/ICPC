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
const int MAX_N = 300 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, N;
ll sum[MAX_N], dp[MAX_N][MAX_N], A[MAX_N], B[MAX_N], cnt[MAX_N];

template<typename T> T gcd(T a, T b) {
    //return (b)? gcd(b, a  % b) : a;
    while (b) { T t = a % b; a = b; b = t; } return a;
}

ll dfs(int l, int r) {
	if (l + 1 >= r) return dp[l][r] = 0;
	if (~dp[l][r]) return dp[l][r];
	ll res = 0;
	int mid = (l + r) / 2;
	if ((r - l) % 2 == 0 && cnt[mid - 1] == mid - l) return dp[l][r] = sum[r] - sum[l];
	if (dfs(l + 1, r - 1) == sum[r - 1] - sum[l + 1] && gcd(A[l], A[r - 1]) != 1) return dp[l][r] = sum[r] - sum[l];
	for (int k = l; k + 1 < r; ++k)
		res = max(dfs(l, k + 1) + dfs(k + 1, r), res);
	return dp[l][r] = res;
}

int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		sum[0] = 0;
		for (int i = 0; i < N; ++i)
			scanf("%lld", A + i);
		for (int i = 0; i < N; ++i) {
			scanf("%lld", B + i);
			sum[i + 1] = sum[i] + B[i];
		}
		memset(dp, -1, sizeof dp);
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i + 1 < N; ++i) {
			int a = i, b = i + 1;
			while (0 <= a && b < N && gcd(A[a], A[b]) != 1ll) {
				--a;
				++b;
				++cnt[i];
			}
			// cout << cnt[i] << endl;
		}
		printf("%lld\n", dfs(0, N));
	}	
	return 0;
}
