// written at 18:33 on 11 Feb 2017 
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
const int MAX_N = 1e5 + 10;

struct P
{
	double x, y;
	P(double x = 0, double y = 0) : x(x), y(y) {}
	void read() { scanf("%lf%lf", &x, &y);} 	
	void write() { printf("(%f, %f)\n", x, y);}
	P operator + (P p) { return P(x + p.x, y + p.y);}
	P operator - (P p) { return P(x - p.x, y - p.y);}
	double det(P p) { return x * p.y - y * p.x;}
	double dot(P p) { return x * p.x + y * p.y;}
	bool operator < (const P & p) const {
		return (x == p.x) ? y < p.y : x < p.x;
	}
}p[MAX_N], ps[MAX_N], qs[MAX_N], ts[MAX_N];

int N;

int convex_hull(P p[], P q[], int n) {
	sort(p, p + n);
	int k = 0;
	rep(i, 0, n) {
		while (k > 1 && (q[k - 1] - q[k - 2]).det(p[i] - q[k - 1]) <= 0) --k;
		q[k++] = p[i];
	}
	int t = k;
	irep(i, n - 1, 0) {
		while (k > t && (q[k - 1] - q[k - 2]).det(p[i] - q[k - 1]) <= 0) --k;
		q[k++] = p[i];
	}
	q[k - 1] = q[0];
	return k - 1;
}

double area(P p[], int n) {
	double res = 0;
	rep(i, 0, n) {	
		res += p[i + 1].det(p[i]);
	}
	return fabs(res);
}

void solve() {
	int n = convex_hull(ps, qs, N);
	memcpy(p, ps, N * sizeof(P));
	double ans = DBL_MAX;
	rep(i, 0, n) {
		int id = lower_bound(ps, ps + N, qs[i]) - ps;
		memcpy(ps, p, N * sizeof(P));
		swap(ps[id], ps[N - 1]);
		int m = convex_hull(ps, ts, N - 1);
		ans = min(ans, area(ts, m));
	}
	printf("%.2f\n", ans / 2.);
}

int main(int argc, char const *argv[])
{
	while (scanf("%d", &N) && N) {
		rep(i, 0, N) ps[i].read();
		solve();
	}
	return 0;
}