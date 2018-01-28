// written at 14:16 on 21 Jan 2018
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
#include <numeric>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 1e3 + 10;
const double eps = 1e-8;
int sgn(double x) { return x < -eps ? -1 : x > eps ? 1 : 0;}
inline double add(double a, double b) {
    if (abs(a + b) < eps * (abs(a) + abs(b))) return 0;
    return a + b;
};
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator + (Point p) { return Point(x + p.x, y + p.y); }
    Point operator - (Point p) { return Point(x - p.x, y - p.y); }
    Point operator * (double d) { return Point(x * d, y * d); }
    bool operator < (Point p) const { return x != p.x? x < p.x : y < p.y; }
    double dot(Point p) { return add(x * p.x, y * p.y); }// 内积
    double det(Point p) { return add(x * p.y, -y * p.x); }// 外积
    Point ver() { return Point(-y, x); }
};
bool on_ln(Point p1, Point p2, Point q) {
    return (p1 - q).det(p2 - q) == 0;
}
Point intersection(Point p1, Point p2, Point q1, Point q2) {
    return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}
int convex_hull(Point *ps, int n, Point *ch) {
    sort(ps, ps + n);
    int k = 0;
    for (int i = 0; i < n; ++i) {
        while (k > 1 && (ch[k - 1] - ch[k - 2]).det(ps[i] - ch[k - 1]) < 0) k--;
        ch[k++] = ps[i];
    }
    for (int i = n - 2, t = k; i >= 0; --i) {
        while (k > t && (ch[k - 1] - ch[k - 2]).det(ps[i] - ch[k - 1]) < 0) k--;
        ch[k++] = ps[i];
    }
    return k;
}

int t, n;
Point p[maxn], ch[maxn];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
        int m = convex_hull(p, n, ch);
        // for (int i = 0; i < m; i++) printf("%f%f\n", ch[i].x, ch[i].y);
        ch[m] = ch[1];
        int ls = 0;
        bool flag = true;
        for (int i = 1; i < m; i++)
            if (!on_ln(ch[i - 1], ch[i + 1], ch[i])) {
                if (i - ls < 2) { flag = false; break; }
                ls = i;
            }
        puts(flag && ls? "YES" : "NO");
    }
    return 0;
}
