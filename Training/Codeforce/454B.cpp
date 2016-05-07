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
const int MAX_N = 1e5 + 10;

const double PI = acos(-1.0);

int main(int argc, char const *argv[])
{
	int n, a[MAX_N], p;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (p = 1; p < n; ++p)
		if (a[p] < a[p - 1])
			break;
	bool flag = true;
	for (int i = p + 1; i < n; ++i)
		if (a[i] < a[i - 1]) {
			flag = false;
			break;
		}
	// printf("%d\n", p);
	if (p == n) {
		printf("0\n");
	}
 	else if (a[n - 1] > a[0] || !flag) {
		printf("-1\n");
	} else printf("%d\n", n - p);
	return 0;
}