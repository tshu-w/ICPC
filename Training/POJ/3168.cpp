// written at 20:57 on 8 Feb 2017 
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
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 5e4 + 10;

struct LINE
{
	int x, y1, y2, id;
	LINE(int a = 0, int b = 0, int c = 0, int d = 0): x(a), y1(b), y2(c), id(d) {};
	bool operator < (const LINE &l) const {
		if (x == l.x) return y1 < l.y1;
		else return x < l.x;
	}	
};

LINE xs[MAX_N], ys[MAX_N];
int N, a, b, c, d;
bool flag[MAX_N];

void check(LINE * xs) {
	int it = 0;
	while (it < 2 * N) {
		int end = xs[it].y2;
		while (it + 1 < 2 * N && xs[it + 1].x == xs[it].x) {
			if (xs[it + 1].y1 <= end)
				flag[xs[it].id] = flag[xs[it + 1].id] = true;
			++it;
			end = max(xs[it].y2, end);
		}
		++it;
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	rep(i, 0, N) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		xs[2 * i] = LINE(a, b, d, i);
		xs[2 * i + 1] = LINE(c, b, d, i);
		ys[2 * i] = LINE(b, a, c, i);
		ys[2 * i + 1] = LINE(d, a, c, i);
	}
	sort(xs, xs + 2 * N); sort(ys, ys + 2 * N);
	check(xs); check(ys);
	int ans = 0;
	rep(i, 0, N) if (!flag[i]) ++ans;
	printf("%d\n", ans);
	return 0;
}
