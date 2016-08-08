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
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, q, A[MAX_N], st[MAX_N][20];

void ST() {
	for (int i = 1; i <= n; ++i) {
		if (i == 1 || A[i] != A[i - 1]) st[i][0] = 1;
		else st[i][0] = st[i - 1][0] + 1;
		// printf("%d ", st[i][0]);
	}
	// printf("\n");
	int k = log(double(n + 1)) / log(2.);
	for (int j = 1; j <= k; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
			// printf("%d ", st[i][j]);
		}
		// printf("\n");
	}

}
int rmq_max(int l, int r) {
	if (l > r)
		return 0;
	int k = log((double)(r - l + 1)) / log(2.);
    // printf("k = %d\n", k);
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main(int argc, char const *argv[])
{
	while (scanf("%d", &n) && n) {
		scanf("%d", &q);
		for (int i = 1; i <= n; ++i)
			scanf("%d", A + i);
		memset(st, 0, sizeof st);
		ST();
		for (int i = 0, l, r; i < q; ++i) {
			scanf("%d%d", &l, &r);
			int k = l;
			while (k <= r && A[k] == A[k - 1]) ++k;
			// cout << l << " " << r << " " << k << endl;
			int cnt = rmq_max(k, r);
			int ans = max(k - l, cnt);
			printf("%d\n", ans);
		}
	}
	return 0;
}