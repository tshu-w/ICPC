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
const int MAX_N = 1e3 + 3;

template <typename T>
inline T sqr(T a) { return a * a;};
int t, n, sumn;
ll a[MAX_N];

inline ll llmax(ll a, ll b) {
	if (a > b)
		return a;
	else 
		return b;
}
int main(int argc, char const *argv[])
{

	cin >> t;
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%lld", a + i);
		sumn = 0;
		ll ans = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				for (int k = j + 1; k < n; ++k) {
					ans = llmax(ans, (a[i] + a[j]) ^ a[k]);
					ans = llmax(ans, (a[k] + a[i]) ^ a[j]);
					ans = llmax(ans, (a[j] + a[k]) ^ a[i]);
				}
		printf("%lld\n", ans);
	}
	return 0;
}