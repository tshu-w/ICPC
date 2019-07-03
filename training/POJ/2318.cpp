// written at 10:33 on 21 Jan 2018
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

const int maxn = 5e3 + 10;

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
    bool operator < (Point p) { return x != p.x? x < p.x : y < p.y; }
    double dot(Point p) { return add(x * p.x, y * p.y); }// 内积
    double det(Point p) { return add(x * p.y, -y * p.x); }// 外积
    Point ver() { return Point(-y, x); }
};

int n, m, X1, X2, Y1, Y2;
int u[maxn], l[maxn], ans[maxn];
Point plu, pld;
bool flag = false;

int main() {
    while (scanf("%d%d%d%d%d%d", &n, &m, &X1, &Y1, &X2, &Y2) == 6) {
        if (flag) puts("");
        memset(ans, 0, sizeof ans);
        flag = true;
        plu = Point(X1, Y2);
        pld = Point(X1, Y1);
        for (int i = 0; i < n; i++)
            scanf("%d%d", u + i, l + i);
        u[n] = X2, l[n] = X2; n++;
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            Point pp = Point(x, y);
            for (int j = 0; j < n; j++) {
                Point p1 = Point(u[j], Y1), p2 = Point(l[j], Y2);
                Point v1 = p2 - p1, v2 = pp - p1;
                if (sgn(v1.det(v2)) < 0) {
                    // printf("%d: %d\n", i, j);
                    ans[j]++;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++)
            printf("%d: %d\n", i, ans[i]);
    }
    return 0;
}
