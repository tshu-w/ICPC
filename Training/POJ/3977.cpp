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
typedef pair<ll, int > Pli;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 40;

template <typename T>
inline T sqr(T a) { return a * a;};

int N;
ll A[MAX_N];
Pli ps[1 << (MAX_N / 2)], ans;

void solve() {
	ans = Pli(LLONG_MAX, 1);
	int n2 = N / 2;
	for (int i = 1; i < 1 << n2; ++i) {
		int cnt = 0; ll sum = 0;
		for (int j = 0; j < n2; ++j)
			if (i >> j & 1)
				sum += A[j], ++cnt;
		if (!cnt) continue;
		ans = min(ans, Pli(llabs(sum), cnt));
		ps[i - 1] = Pli(sum, cnt);
	}
	sort(ps, ps + (1 << n2) - 1);
	int m = 1;
	for (int i = 1; i < (1 << n2) - 1; ++i)
		if (ps[m - 1].first != ps[i].first)
			ps[m++] = ps[i];

	for (int i = 1; i < 1 << (N - n2); ++i) {
		int cnt = 0; ll sum = 0;
		for (int j = 0; j < (N - n2); ++j)
			if (i >> j & 1)
				sum += A[j + n2], ++cnt;
		if (!cnt) continue;
		ans = min(ans, Pli(llabs(sum), cnt));

		int it = lower_bound(ps, ps + m, Pli(-sum, 0)) - ps;
		if (it)
			ans = min(ans, Pli(llabs(ps[it - 1].first + sum), cnt + ps[it - 1].second));
		if (it != m)
			ans = min(ans, Pli(llabs(ps[it].first + sum), cnt + ps[it].second));
	}
	printf("%lld %d\n", ans.first, ans.second);
}

int main(int argc, char const *argv[])
{
	while (scanf("%d", &N) && N) {
		for (int i = 0; i < N; ++i)
			scanf("%lld", A + i);
		solve();
	}
	return 0;
}