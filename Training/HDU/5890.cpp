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
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50 + 5;
const int MAX_M = 1e6 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, n, m, A[MAX_N];
bool flag[MAX_N][MAX_N][MAX_N];
bitset<90> dp[11];

bool check(int x, int y, int z) {	
	for (int i = 0; i < 11;	++i)
		dp[i].reset();
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		if (i != x && i != y && i != z)
			for (int j = 10; j > 0; --j)
				dp[j] |= dp[j - 1] << A[i];
	}
	return dp[10][87];
}

int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", A + i);
		for (int i = 0; i < n; ++i)
			for (int j = i; j < n; ++j)
				for (int k = j; k < n; ++k)
					flag[i][j][k] = check(i, j, k);
		scanf("%d", &m);
		while (m--) {
			int q[3];
			for (int i = 0; i < 3; ++i) {
				scanf("%d", q + i);
				--q[i];
			}
			sort(q, q + 3);
			if (flag[q[0]][q[1]][q[2]])
				puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
