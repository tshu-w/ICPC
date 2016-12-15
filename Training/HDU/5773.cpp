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
const int MAX_N = 1e5 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, cases = 0, N, S[MAX_N];

ll lis(int n, vector<int> &A) {
	int dp[MAX_N];
	fill(dp, dp + n, INF);
	for (int i = 0; i < n; ++i)
		*lower_bound(dp, dp + n, A[i]) = A[i];
	return lower_bound(dp, dp + n, INF) - dp;
}

int main(int argc, char const *argv[])
{
	cin >> t;
	while (t--) {
		cin >> N;
		ll cnt = 0;
		vector<int> A;
		for (int i = 0; i < N; ++i) {
			scanf("%d", S + i);
			if (S[i]) A.push_back(S[i] - cnt);
			else ++cnt; 
		}
		printf("Case #%d: %lld\n", ++cases, lis(N - cnt, A) + cnt);
	}	
	return 0;
}