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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, h, m;

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	scanf("%d:%d", &h, &m);
	if (n == 24) {
		if (h > 23)
			h = h % 10;
		if (m >= 60)
			m = m % 10;
	} else {
		if (h == 0)
			h = 1;
		else
			if (h > 12) {
				if (h % 10 != 0)
					h = h % 10;
				else h = 10;
			}
		if (m >= 60)
			m = m % 10;
	}
	printf("%02d:%02d\n", h, m);
	return 0;
}