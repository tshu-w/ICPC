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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1e9 + 10;
const int MAX_N = 1e5 + 10;

const double PI = acos(-1.0);

int main(int argc, char const *argv[])
{
	int n, dpi[MAX_N], dpd[MAX_N], ans = 1;
	ll a[MAX_N];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%I64d", &a[i]);
	// for (int i = 0; i < n; ++i)
	// 	printf("%lld ", a[i] / 100000);
	// printf("\n");
	fill(dpi, dpi + n, 1);
	for (int i = n - 2; i >= 0; --i)
		if (a[i + 1] > a[i])
			dpi[i] = dpi[i + 1] + 1;
	fill(dpd, dpd + n, 1);
	for (int i = 1; i < n; ++i)
		if (a[i - 1] < a[i])
			dpd[i] = dpd[i - 1] + 1;
	// for (int i = 0; i < n; ++i)
	// 	printf("%d ", dpi[i]);
	// printf("\n");
	// for (int i = 0; i < n; ++i)
	// 	printf("%d ", dpd[i]);
	// printf("\n");

	for (int i = 0; i < n; ++i)
		if (i != 0 && i != n - 1 && a[i + 1] - a[i - 1] >= 2) {
			ans = max(ans, dpd[i - 1] + dpi[i + 1] + 1);
			// printf("%d %d\n", i, ans);
		} else {
			ans = max(ans, dpd[i - 1] + 1);
			ans = max(ans, dpi[i + 1] + 1);
		}
	printf("%d\n", ans);
	// for (int i = 0; i < n; ++i) {
	// 	*lower_bound(dp, dp + n, a[i]) = a[i];
	// 	// for (int j = 0; j < n; ++j)
	// 	// 	printf("%lld ", dp[j]);
	// 	// printf("\n");
	// }
	// printf("%d\n", (int)(lower_bound(dp, dp + n, INF) - dp) + 1);
	return 0;
}