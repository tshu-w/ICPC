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
const int MAX_M = 2000 + 10;
const int MAX_N = 30;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, M, dp[MAX_M][MAX_M], cost[MAX_N];
char s[MAX_M], ch[5];

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &M);
	scanf("%s", s);
	for (int i = 0, a, b; i < N; ++i) {
		scanf("%s%d%d", ch, &a, &b);
		cost[ch[0] - 'a'] = min(a, b);
	}
	memset(dp, 0, sizeof dp);
	for (int i = M - 1; i >= 0; --i)
		for (int j = i; j < M; ++j)
			if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
			else dp[i][j] = min(dp[i + 1][j] + cost[s[i] - 'a'], dp[i][j - 1] + cost[s[j] - 'a']);
	printf("%d\n", dp[0][M - 1]);
	return 0;
}