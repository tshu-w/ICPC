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
typedef pair<int, int> pii;

const int INF = INT_MAX;
const int MAX_N = 100 + 10;

const double PI = acos(-1.0);

int main(int argc, char const *argv[])
{
	int n;
	pii s[MAX_N];
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; ++i)
			scanf("%d %d", &s[i].second, &s[i].first);
		sort(s, s + n);
		// for (int i = 0; i < n; ++i)
			// printf("%d %d %d\n", i, s[i].second, s[i].first);
		int ans = 0, t = s[0].first;
		for (int i = 1; i < n; ++i)
			if (t <= s[i].second) {
				++ans;
				t = s[i].first;
				// printf("%d\n", i);
			}
		printf("%d\n", ans + 1);
	}
	return 0;
}