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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int a, b, c, d, e, f;
int u[] = {0, 5, 3, 1};

int main(int argc, char const *argv[])
{
	while (~scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) && (a + b + c + d + e + f)) {
		int n = d + e + f + (c + 3) / 4;
		int y = 5 * d + u[c % 4];
		if (b > y)
			n += (b - y + 8) / 9;
		int x = 36 * n - 36 * f - 25 * e - 16 * d - 9 * c - 4 * b;
		if (a > x)
			n += (a - x + 35) / 36;
		printf("%d\n", n);
	}
	return 0;
}