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

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e5 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

char s;
int n, k, ans = 1, a[MAX_N], b[MAX_N], an = 0, bn = 0;

int main(int argc, char const *argv[])
{
	cin >> n >> k;
	getchar();
	a[an++] = b[bn++] = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%c", &s);
		if (s == 'a')
			a[an++] = i + 1;
		else 
			b[bn++] = i + 1;
	}
	a[an++] = n + 1;
	b[bn++] = n + 1;
	for (int i = 0; i < an; ++i) 
		if (i + k + 1 < an)
			ans = max(ans, a[i + k + 1] - a[i] - 1);
		else ans = max(ans, a[an - 1] - a[i] - 1);
	for (int j = 0; j < bn; ++j)
		if (j + k + 1 < bn)
			ans = max(ans, b[j + k + 1] - b[j] - 1);
		else ans = max(ans, b[bn - 1] - b[j] - 1);
	cout << ans<< endl;
	return 0;
}