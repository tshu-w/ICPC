//#include <bits/stdc++.h>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <bitset>

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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 44;
const int MAX_M = 1 << 21;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, tt = 0, N, M, A[MAX_N];
ll dp[MAX_M][2], ans;

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; ++i)
			scanf("%d", A + i);
		memset(dp, 0, sizeof dp);
		dp[0][0 & 1] = 1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < MAX_M; ++j)
				dp[j][(i + 1) & 1] = dp[j][i & 1] + dp[j ^ A[i]][i & 1];
		}
		ans = 0;
		for (int i = M; i < MAX_M; ++i)
			ans += dp[i][N & 1];
		printf("Case #%d: %lld\n", ++tt, ans);
	}	
	return 0;
}