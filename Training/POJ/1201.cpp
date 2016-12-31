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

struct Range
{
	int l, r, c;
};
bool cmp(const Range a, const Range b) {
	return a.r < b.r;
}

int N, bit[MAX_N + 1], ans, maxr;
bool flag[MAX_N];
Range P[MAX_N];

void add(int i, int x) {
	while (i <= maxr) {
		bit[i] += x;
		i += i & -i;
	}
}
int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}
int sum(int l, int r) {
	return sum(r) - sum(l - 1);
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d%d", &P[i].l, &P[i].r, &P[i].c);
		maxr = max(P[i].r, maxr);
	}
	sort(P, P + N, cmp);
	for (int i = 0; i < N; ++i)
		if (sum(P[i].l, P[i].r) < P[i].c) {
			int res = P[i].c - sum(P[i].l, P[i].r), p = P[i].r;
			ans += res;
			while (res--) {
				while (p >= P[i].l && flag[p]) --p;
				add(p, 1);
				flag[p--] = true;
			}
		}
	printf("%d\n", ans);
	return 0;
}