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
const ll LLINF = LLONG_MAX;
const int MAX_N = 20;

template <typename T>
inline T sqr(T a) { return a * a;};

int A[MAX_N], n, t, x, y;

int cal(int l, int r) {
	if (A[l] == 0 && l + 1 < r) return -1;
	int res = 0;
	for (int i = l; i < r; ++i)
		res = res * 10 + A[i];
	return res;
}

int main(int argc, char const *argv[])
{
	scanf("%d ", &t);
	while (t--) {
		string line;
		getline(cin, line);
		stringstream ss(line);
		n = 0;
		while (ss >> x) 
			A[n++] = x;
		int ans = INF;
		do {
			x = cal(0, n >> 1);
			y = cal(n >> 1, n);
			if (x + 1 && y + 1) ans = min(ans, abs(x - y));
			x = cal(0, (n >> 1) + 1);
			y = cal((n >> 1) + 1, n);
			if (x + 1 && y + 1) ans = min(ans, abs(x - y));
		} while (next_permutation(A, A + n));	
		printf("%d\n", ans);
	}
	return 0;
}