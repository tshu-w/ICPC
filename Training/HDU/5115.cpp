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
const int MAX_N = 200 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, tt = 0, N, A[MAX_N], B[MAX_N], dp[MAX_N][MAX_N];

int dfs(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r]; 
	if (l + 1 == r) return dp[l][r] = 0;
	dp[l][r] = INF;
	for (int k = l + 1; k < r; ++k)
		dp[l][r] = min(dp[l][r], B[l] + B[r] + dfs(l, k) + dfs(k, r));
	return dp[l][r];
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		int sum = 0;
		for (int i = 1; i <= N; ++i)
			scanf("%d", A + i), sum += A[i];
		for (int i = 1; i <= N; ++i)
			scanf("%d", B + i);
		memset(dp, -1, sizeof dp);
		A[0] = B[0] = A[N + 1] = B[N + 1] = 0;
		sum += dfs(0, N + 1);
		printf("Case #%d: %d\n", ++tt, sum);
	}
	return 0;
}