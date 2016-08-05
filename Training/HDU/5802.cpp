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

int dfs(int p, int q, int s) {
	if (p == q)
		return 0;
	int x = 1, step = 0;
	while (p - x >= q) {
		p -= x;
		x <<= 1; ++step;
	}
	x >>= 1;
	if (p == q) return step;
	// cout << p << " " << q << endl;
	// cout << step << endl;
	int pp = max(0, p - 2 * x), ss = min(q - pp, s);	
	return min(step + 1 + q - pp - ss, dfs(p, q, s + 1) + step + 1);
}
int main(int argc, char const *argv[])
{
	int t, p, q;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &p, &q);
		printf("%d\n", (p <= q)? q - p : dfs(p, q, 0));
	}
	return 0;
}