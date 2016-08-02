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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int cnt(ll n) {
	int res = 0;
	while (n) {
		if (n & 1) ++res;
		n >>= 1;
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int t, tt = 0, l, r;
	ll d;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%d%d", &d, &l, &r);
		++d;
		while (true) {
			int n = cnt(d);
			if (l <= n && n <= r)
				break;
			if (n < l) {
				int x = 0;
				while (d & (1ll << x)) ++x;
				d |= 1ll << x;
			} else {
				int x = 0;
				while (!(d & (1ll << x))) ++x;
				d += 1ll << x;
			}
		}
		printf("Case #%d: %lld\n", ++tt, d);
	}
	return 0;
}