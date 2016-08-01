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
const int MAX_N = 7500;
const int coin[] = {1, 5, 10, 25, 50};

template <typename T>
inline T sqr(T a) { return a * a;};

int N;
ll dp[MAX_N][5];

int main(int argc, char const *argv[])
{
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < 5; ++i)
		dp[0][i] = 1LL;
	for (int i = 1; i < MAX_N; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j < 5; ++j) {
			dp[i][j] += dp[i][j - 1];
			if (i - coin[j] >= 0)
				dp[i][j] += dp[i - coin[j]][j];	
		}
	}
	while (~scanf("%d", &N)) {
		printf("%lld\n", dp[N][4]);
	}
	return 0;
}