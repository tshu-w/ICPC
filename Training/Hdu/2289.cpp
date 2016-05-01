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

const int INF = INT_MAX;
const int MAX_N = 1000 + 10;

const double PI = acos(-1.0);

int main(int argc, char const *argv[])
{
	int n, q, a[MAX_N], t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) 
			scanf("%d", &a[i]);
		scanf("%d", &q);
		for (int i = 0; i < q; ++i) {
			int ans = 0, l, r;
			scanf("%d %d", &l, &r);
			for (int j = l; j <= r; ++j)
				ans = max(a[j], ans);
			printf("%d\n", ans);
		}
	}
	return 0;
}