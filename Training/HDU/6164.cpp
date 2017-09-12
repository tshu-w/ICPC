// written at 15:04 on 22 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 1e3 + 10;
const double EPS = 1e-8;
int sgn(double x) { return x < -EPS ? -1 : x > EPS ? 1 : 0;}
inline double add(double a, double b) {
    if (abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
    return a + b;
};
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator + (Point p) { return Point(x + p.x, y + p.y); }
    Point operator - (Point p) { return Point(x - p.x, y - p.y); }
    Point operator * (double d) { return Point(x * d, y * d); }
    bool operator < (Point p) {return x != p.x? x < p.x : y < p.y;}
    double dot(Point p) { return add(x * p.x, y * p.y); }// 内积
    double det(Point p) { return add(x * p.y, -y * p.x);}// 外积
};
bool on_seg(Point p1, Point p2, Point q) {
    return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}
Point intersection(Point p1, Point p2, Point q1, Point q2) {
    return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

int t, n, m;
double k[maxn];
Point p[maxn], v, d;

int main() {
    while (~scanf("%d", &n)) {
        v.x = v.y = 0.0;
        for (int i = 0; i < n; i++) scanf("%lf%lf%lf", &p[i].x, &p[i].y, k + i);
        scanf("%lf%lf", &d.x, &d.y);
        int cnt = 0;
        double m = 1;
        while (m - 1e-4 > EPS) {
            cnt++;
            Point v2 = v + d;
            for (int i = 0; i < n; i++) {
                int j = i + 1; if (j >= n) j -= n;
                Point X = intersection(v, v2, p[i], p[j]);
                // cerr << "X == " << X.x << " " << X.y << endl;
                if (sgn(X.x - v.x) == 0 && sgn(X.y - v.y) == 0) continue;
                if (sgn(X.x - p[i].x) == 0 && sgn(X.y - p[i].y) == 0) { m = 1e-5; break; }
                if (sgn(X.x - p[j].x) == 0 && sgn(X.y - p[j].y) == 0) { m = 1e-5; break; }
                if (on_seg(p[i], p[j], X)) {
                    // cerr << "In " << i << endl;
                    m = m * k[i];
                    Point dd = Point(p[j].y - p[i].y, p[i].x - p[j].x);
                    Point XX = X + dd;
                    Point tmp = intersection(v, v + (p[j] - p[i]), X, XX);
                    Point vv = tmp * 2 - v;
                    d = vv - X;
                    v = X;
                    break;
                }
            }
            // cerr << v.x << ", " << v.y << endl;
            // cerr << d.x << ", " << d.y << endl;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
