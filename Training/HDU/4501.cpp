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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 200 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, v1, v2, k, a[MAX_N], b[MAX_N], val[MAX_N], dp[MAX_N][MAX_N][20];

int main(int argc, char const *argv[])
{
	while (~scanf("%d%d%d%d", &N, &v1, &v2, &k)) {
		for (int i = 0; i < N; ++i)
			scanf("%d%d%d", a + i, b + i, val + i);
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < N; ++i)
			for (int j = v1; j >= 0; --j)
				for (int l = v2; l >= 0; --l)
					for (int m = k; m >= 0; --m) {
						int flag = 0;
						if (j >= a[i]) flag = max(flag, dp[j - a[i]][l][m] + val[i]);
						if (l >= b[i]) flag = max(flag, dp[j][l - b[i]][m] + val[i]);
						if (m >= 1)    flag = max(flag, dp[j][l][m - 1]    + val[i]);
						dp[j][l][m] = max(flag, dp[j][l][m]);
					}
		printf("%d\n", dp[v1][v2][k]);
	}	
	return 0;
}