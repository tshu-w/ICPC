// written at 15:45 on 12 Feb 2017 
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
const double EPS = 1e-10;
int sgn(double x) { return x < -EPS ? -1 : x > EPS ? 1 : 0;}

struct Point
{
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
    void read() { scanf("%lf%lf", &x, &y);}
    void write() { printf("(%lf, %lf)\n", x, y);}
    Point operator + (Point p) { return Point(x + p.x, y + p.y);}
    Point operator - (Point p) { return Point(x - p.x, y - p.y);}
    Point operator * (double c) { return Point(c * x, c * y);}
    double dot(Point p) { return x * p.x + y * p.y;}
    double det(Point p) { return x * p.y - y * p.x;}
    bool operator < (Point p) { return x != p.x? x < p.x : y < p.y;}
};
typedef pair<Point, Point> Line;

int N;
Line ls[MAX_N];
Point ps[MAX_N];

inline double atan(Point p) {
    return atan2(p.y, p.x);
}
bool cmp(Line &l1, Line &l2) {
    return atan(l1.second - l1.first) < atan(l2.second - l2.first);
}
inline double cross(Line l, Point p) {
    return (l.second - l.first).det(p - l.first);
}
inline bool parallel(Line l1, Line l2) {
    return (l2.second - l2.first).det(l1.second - l1.first) == 0;
}
Point intersaction(Line &l1, Line &l2) {
    Point& a1 = l1.first, &a2 = l1.second;
    Point& b1 = l2.first, &b2 = l2.second;
    Point a = a2 - a1, b = b2 - b1, s = b1 - a1;
    return a1 + a * (b.det(s) / b.det(a));
}
int halfplane_intersaction(Line *hp, int n, Point *ch) {
    sort(hp, hp + n, cmp);
    vector<Line> ls(n);
    vector<Point> ps(n);
    int l, r;
    ls[l = r = 0] = hp[0];
    for (int i = 0; i < n; ++i) {
        while (l < r && cross(hp[i], ps[r - 1]) < 0) --r;
        while (l < r && cross(hp[i], ps[l]) < 0) ++l;
        ls[++r] =  hp[i];
        if (parallel(ls[r - 1], hp[i]) && cross(ls[--r], hp[i].first) < 0) ls[r] = hp[i];
        if (l < r) ps[r - 1] = intersaction(ls[r], ls[r - 1]);
    }
    while(l < r && cross(ls[l], ps[r - 1]) < 0) --r;
    if (r - l <= 1) return 0;
    ps[r] = intersaction(ls[l], ls[r]);
    int m = 0;
    for (int i = l; i <= r; ++i) ch[m++] = ps[i];
    return m;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		rep(i, 0, N) ps[i].read(); ps[N] = ps[0];
		rep(i, 0, N) ls[i] = Line(ps[i], ps[i + 1]);
		puts((halfplane_intersaction(ls, N, ps) > 0)? "YES" : "NO");
	}
	return 0;
}