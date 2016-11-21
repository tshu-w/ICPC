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
const int MAX_N = 1e5 + 10;

int N, X[MAX_N], Y[MAX_N], ans, w, h;
Pii px[MAX_N], py[MAX_N];

int bit[MAX_N];
void add(int i, int x) {
	while (i <= w) {
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

int compress(int *A) {
	vector<int> v;
	for (int i = 0; i < N; ++i)
		v.push_back(A[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < N; ++i)
		A[i] = lower_bound(v.begin(), v.end(), A[i]) - v.begin() + 1;
	return v.size();
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d%d", X + i, Y + i);
	w = compress(X);
	h = compress(Y);
	for (int x = 1; x <= w; ++x)
		px[x].first = INF, px[x].second = 0;
	for (int i = 0; i < N; ++i) {
		px[X[i]].first = min(px[X[i]].first, Y[i]);
		px[X[i]].second = max(px[X[i]].second, Y[i]);
		py[i] = Pii(Y[i], X[i]);
	}
	sort(py, py + N);
	for (int y = 1; y <= h; ++y) {
		int l = lower_bound(py, py + N, Pii(y, 0)) - py, r = lower_bound(py, py + N, Pii(y, INF)) - py;
		for (int j = l; j < r; ++j) {
			int x = py[j].second;
			if (px[x].first == y)
				add(x, 1);
		}
		ans += sum(py[r - 1].second) - sum(py[l].second - 1);
		for (int j = l; j < r; ++j) {
			int x = py[j].second;
			if (px[x].second == y)
				add(x, -1);
		}
	}
	printf("%d\n", ans);
	return 0;
}