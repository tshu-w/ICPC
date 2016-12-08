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
const int MAX_N = 2e5 + 10;

int N, A[MAX_N], B[MAX_N], C[MAX_N], bit[MAX_N], mp[MAX_N];

void add(int i, int x) {
	while (i <= N) {
		bit[i] += x;
		i += i & -i;
	}
}

int sum(int i) {
	int res = 0;
	while (i) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

ll diff(int A[], int B[]) {
	ll res = 0;
	for (int i = 1; i <= N; ++i)
		mp[A[i]] = i;
	memset(bit, 0, sizeof bit);
	for (int i = N; i >= 1; --i) {
		res += sum(mp[B[i]]);
		add(mp[B[i]], 1);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d", &N)) {
		for (int i = 1; i <= N; ++i)
			scanf("%d", A + i);
		for (int i = 1; i <= N; ++i)
			scanf("%d", B + i);
		for (int i = 1; i <= N; ++i)
			scanf("%d", C + i);
		ll ans = (ll) N * (N - 1) / 2;
		ans -= (diff(A, B) + diff(A, C) + diff(B, C)) / 2;
		printf("%lld\n", ans);
	}
	return 0;
}