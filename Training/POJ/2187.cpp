// written at 15:43 on 10 Feb 2017 
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
const double EPS = 1e-8;

double add(double a, double b) {
	if (abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
	return a + b;
} 
struct P {
	double x, y;
	// P() {}
    inline void read () { scanf("%lf%lf", &x, &y); }
    inline void write () { printf("%f %f", x, y); }
	P(double x = 0, double y = 0) : x(x), y(y) {}

	P operator + (P p) {
		return P (add(x, p.x), add(y, p.y));
	}
	P operator - (P p) {
		return P (add(x, -p.x), add(y, -p.y));
	}
	P operator * (P p) {
		return P (x * p.x, y * p.y);
	}
	double dot(P p) {  //内积
		return add(x * p.x, y * p.y);
	}
	double det(P p) { //外积
		return add(x * p.y, -y * p.x);
	}
};
int N;
P ps[MAX_N];

bool cmp_x(P p, P q) {
	if (p.x == q.x) return p.y < q.y;
	else return p.x < q.x;
}
vector<P> convex_hull(P *ps, int n) {
	sort(ps, ps + n, cmp_x);
	int k = 0;
	vector<P> qs(n * 2);
	for (int i = 0; i < n; ++i) {
		while (k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) k--;
		qs[k++] = ps[i];
	}
	for (int i = n - 2, t = k; i >= 0; --i) {
		while (k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) k--;
		qs[k++] = ps[i];
	}
	qs.resize(k - 1);
	return qs;
}

double dist(P p, P q) {
	return (p - q).dot(p - q);
}

void solve() {
	vector<P> qs = convex_hull(ps, N);
	int n = qs.size();
	if (n == 2) {
		printf("%.0f\n", dist(qs[0], qs[1]));
		return ;
	}
	int i = 0, j = 0;
	rep(k, 0, n) {
		if (!cmp_x(qs[i], qs[k])) i = k;
		if (cmp_x(qs[j], qs[k])) j = k;
	} double res = 0;
	int si = i, sj = j;
	while (i != sj || j != si) {
		res = max(res, dist(qs[i], qs[j]));
		if ((qs[(i + 1) % n] - qs[i]).det(qs[(j + 1) % n] - qs[j]) < 0)
			i = (i + 1) % n;
		else j = (j + 1) % n;
	}
	printf("%.0f\n", res);
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	rep(i, 0, N) ps[i].read();
	solve();
	return 0;
}