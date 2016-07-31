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
const int MAX_N = 100 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, A[MAX_N], dp[MAX_N][3]; 
int main(int argc, char const *argv[])
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		scanf("%d", A + i);
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j)
			dp[i][0] = max(dp[i - 1][j], dp[i][0]);
		if (A[i] == 1) {
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
			dp[i][2] = 0;
		}
		if (A[i] == 2) {
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
			dp[i][1] = 0;
		}
		if (A[i] == 3) {
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 3; ++i)
		ans = max(dp[N][i], ans);
	cout << N - ans << endl;
	return 0;
}