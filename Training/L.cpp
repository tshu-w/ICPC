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
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, d, a, b, s, P[MAX_N], in, de, cnt;

int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d", &n, &d, &a, &b);	
	for (int i = 0; i < n; ++i)
		scanf("%d", P + i);
	in = de = 0;
	for (int i = 1; i < n; ++i) {
		if (P[i] > P[i - 1]) {
			++in; de = 0;
			cnt = min(in * a, d / P[i]);
			s += cnt;
			d -= P[i] * cnt;
		}
		else if (P[i] < P[i - 1]) {
			++de; in = 0;
			cnt = min(de * b, s);
			s -= cnt;
			d += P[i] * cnt;
		}
		// printf("%d %d\n", d, s);
	}
	printf("%d %d\n", d, s);
	return 0;
}