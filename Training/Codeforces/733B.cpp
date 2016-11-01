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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, l[MAX_N], r[MAX_N], L, R, ans;

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)	{
		scanf("%d%d", l + i, r + i);
		L += l[i];
		R += r[i];
	}
	ans = abs(L - R);
	// cout << L << " " << R << endl;
	int it = -1;
	for (int i = 0; i < N; ++i) {
		L = L - l[i] + r[i];
		R = R - r[i] + l[i];
		if (ans < abs(L - R)) {
			ans = abs(L - R);
			it = i;
		}
		L = L + l[i] - r[i];
		R = R + r[i] - l[i];
	}
	printf("%d\n", it + 1);
	return 0;
}