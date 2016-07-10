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
const int MAX_N = 1e5 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

int main(int argc, char const *argv[])
{
	int t, n, S, a[MAX_N];
	cin >> t;
	while (t--) {
		cin >> n >> S;
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		int res = n + 1;
		int s = 0, t = 0, sum = 0;
		for (;;) {
			while (t < n && sum < S) 
				sum += a[t++];
			if (sum < S) break;
			res = min(res, t - s);
			sum -= a[s++];
		}
		if (res > n) 
			res = 0;
		printf("%d\n", res);
	}
	return 0;
}