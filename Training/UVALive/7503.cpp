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
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e6 + 10;

int T;
double A, B;

bool equal(double a, double b) {
	return fabs(a - b) < 1e-6;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		scanf("%lf%lf", &A, &B);
		if (B == 0.01 || B == 0.1 || B == 1 || B == 10 || B == 100) {
			if (A == 2 * B)
				printf("Case #%d: 0.01\n", i);
			else printf("Case #%d: 0.02\n", i);
		}
		else printf("Case #%d: 0.01\n", i);
	}	
	return 0;
}