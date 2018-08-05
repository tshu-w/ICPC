// written at 10:36 on 04 Aug 2018
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 2e5 + 10;
const double eps = 1e-8;
int sgn(double x) { return x < -eps ? -1 : x > eps ? 1 : 0;}
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    void print() { printf("(%.2lf, %.2lf)\n", x, y); }
    Point operator + (Point p) { return Point(x + p.x, y + p.y); }
    Point operator - (Point p) { return Point(x - p.x, y - p.y); }
    Point operator * (double d) { return Point(x * d, y * d); }
    bool operator < (Point p) const { return x != p.x? x < p.x : y < p.y; }
    double dot(Point p) { return x * p.x + y * p.y; }// 内积
    double det(Point p) { return x * p.y - y * p.x; }// 外积
    Point ver() { return Point(-y, x); }
};
Point intersection(Point p1, Point p2, Point q1, Point q2) {
    return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

int n, m;
double l[maxn], r[maxn], sum[maxn], sy, a, b;
Point A, B;

int main() {
    scanf("%lf%lf%lf", &sy, &a, &b);
    A = Point(a, sy); B = Point(b, sy);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lf%lf", l + i, r + i), sum[i + 1] += sum[i] + r[i] - l[i];
    scanf("%d", &m);
    for (int i = 0, x, y; i < m; i++) {
        scanf("%d%d", &x, &y);
        Point p = Point(x, y);
        Point AA = intersection(p, A, Point(0, 0), Point(1, 0)), BB = intersection(p, B, Point(0, 0), Point(1, 0));
        int j = upper_bound(r, r + n, AA.x) - r; int k = upper_bound(r, r + n, BB.x) - r;
        double ans = 0;
        if (j < n) ans -= max(0., AA.x - l[j]);
        if (k < n) ans -= r[k] - max(l[k], BB.x);
        ans += sum[min(k + 1, n)] - sum[j];
        printf("%.12f\n", ans * (-sy + y) / y);
    }
    return 0;
}
