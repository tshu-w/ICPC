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

int N, X[MAX_N];
ll M;

bool C(int median) {
	ll res = 0;
	for (int i = 0; i < N; ++i) {
		int tmp = median + X[i];
		res += lower_bound(X, X + N, tmp) - X - i - 1;
	}
	return res < M;
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d", &N)) {
		M = (ll)N * (N - 1) / 2;
		M = (M + 1) / 2;
		for (int i = 0; i < N; ++i)
			scanf("%d", X + i);
		sort(X, X + N);
		int lb = 0, ub = INF;
		while (ub - lb > 1) {
			int mid = (ub - lb) / 2 + lb;
			if (C(mid)) lb = mid;
			else ub = mid;
		}
		printf("%d\n", lb);
	}	
	return 0;
}