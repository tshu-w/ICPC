// written at 10:33 on 21 Feb 2018
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

const int maxn = 3;
const double eps = 1e-8;

int sgn(double x) { return x < -eps ? -1 : x > eps ? 1 : 0;}
inline double add(double a, double b) {
    if (abs(a + b) < eps * (abs(a) + abs(b))) return 0;
    return a + b;
};
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    void read() { scanf("%lf%lf", &x, &y); }
    void write() { printf("(%lf, %lf)", x, y); }
    bool operator == (const Point& p) const { return sgn(x - p.x) == 0 && sgn(y - p.y) == 0; }
    bool operator < (const Point& p) const { return x != p.x? x < p.x : y < p.y; }
    Point operator + (const Point& p) { return Point(x + p.x, y + p.y); }
    Point operator - (const Point& p) { return Point(x - p.x, y - p.y); }
    Point operator * (double d) { return Point(x * d, y * d); }
    double dot(Point p) { return add(x * p.x, y * p.y); }// 内积
    double det(Point p) { return add(x * p.y, -y * p.x); }// 外积
    Point ver() { return Point(-y, x); }
};
struct Circle {
    Point o;
    double r;
    Circle () {}
    Circle (Point o, double r = 0): o(o), r(r) {}
    void read () { o.read(), scanf("%lf", &r); }
    Point point(double rad) { return Point(o.x + cos(rad)*r, o.y + sin(rad)*r); }
    double getArea (double rad) { return rad * r * r / 2; }
};

double getAngle (Point u) { return atan2(u.y, u.x); }

double dis(Point p1, Point p2) {
    return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

int getCircleCircleIntersection (Circle o1, Circle o2, vector<Point>& sol) {
    double d = dis(o1.o, o2.o);
    if (sgn(d) == 0) {
        if (sgn(o1.r - o2.r) == 0) return -1;
        return 0;
    }
    if (sgn(o1.r + o2.r - d) < 0) return 0;
    if (sgn(fabs(o1.r - o2.r) - d) > 0) return 0;

    double a = getAngle(o2.o - o1.o);
    double da = acos((o1.r*o1.r + d*d - o2.r*o2.r) / (2*o1.r*d));

    Point p1 = o1.point(a-da), p2 = o1.point(a+da);

    sol.push_back(p1);
    if (p1 == p2) return 1;
    sol.push_back(p2);
    return 2;
}

bool onCircle(Circle c, Point p) {
    return sgn(dis(c.o, p) - c.r) == 0;
}

int n, e, v, c;
Circle C[maxn];
vector<Point> P;
bool flag[maxn];

void dfs(int i) {
    flag[i] = true;
    for (int j = 0; j < n; j++)
        if (!flag[j])
            for (int k = 0; k < SZ(P); k++)
                if (onCircle(C[i], P[k]) && onCircle(C[j], P[k])) dfs(j);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) C[i].read();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) getCircleCircleIntersection(C[i], C[j], P);
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    v = P.size();
    for (int i = 0; i < v; i++)
        for (int j = 0; j < n; j++)
            if (onCircle(C[j], P[i])) e++;
    for (int i = 0; i < n; i++)
        if (!flag[i]) dfs(i), c++;
    // cout << e << " " << v << " " << c << endl;
    printf("%d\n", e - v + c + 1);
    return 0;
}
