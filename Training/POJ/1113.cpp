// written at 17:42 on 10 Feb 2017 
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
const int MAX_N = 1e3 + 10;

struct P {
	double x, y;
	inline void read() {scanf("%lf%lf", &x, &y);}
	P(double x = 0, double y = 0) : x(x), y(y) { }
	double dot(P p) {
		return x * p.x + y * p.y;
	}
	double det(P p) {
		return x * p.y - y * p.x;
	}
	P operator + (P p) {
		return P(x + p.x, y + p.y);
	}
	P operator - (P p) {
		return P(x - p.x, y - p.y);
	}
	bool operator < (const P& p) const {	
		if (x == p.x) return y < p.y;
		else return x < p.x;
	}
};

double dist(P p, P q) {
	return sqrt((p - q).dot(p - q));
}

int N, L;
P ps[MAX_N];
double c = 0.;

vector<P> convex_hull(P *ps, int n) {
	sort(ps, ps + n);
	int k = 0;
	vector<P> qs(n * 2);
	rep(i, 0, n) {
		while (k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) --k;
		qs[k++] = ps[i];
	}
	int t = k;
	irep(i, n - 1, 0) {
		while (k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) --k;
		qs[k++] = ps[i];
	}
	qs.resize(k - 1);
	return qs;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &L);
	rep(i, 0, N) ps[i].read();
	vector<P> qs = convex_hull(ps, N);
	rep(i, 0, qs.size())
		c += dist(qs[i], qs[(i + 1) % qs.size()]);
	printf("%.0f\n", 2. * pi * L + c);
	return 0;
}