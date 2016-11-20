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

int N, a;
char ch[5], YN[5];

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	int lb = -2e9, ub = 2e9 + 1;
	for (int i = 0; i < N; ++i) {
		scanf("%s%d%s", ch, &a, YN);
		if (strlen(ch) == 1) {
			if (ch[0] == '<') {
				if (YN[0] == 'Y') // <
					ub = min(ub, a);
				else // >=
					lb = max(a, lb);
			} else {
				if (YN[0] == 'Y') // >
					lb = max(a + 1, lb);
				else // <=
					ub = min(a + 1, ub);
			}
		} else { // =
			if (ch[0] == '<') {
				if (YN[0] == 'Y') // <=
					ub = min(a + 1, ub);
				else // >
					lb = max(a + 1, lb);
			} else {
				if (YN[0] == 'Y') // >=
					lb = max(a, lb);
				else // <
					ub = min(ub, a);
			}
		}
	}
	if (lb >= ub) printf("Impossible\n");
	else printf("%d\n", lb);
	return 0;
}