// written at 14:28 on 23 Jan 2017 
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
const int MAX_N = 1e2 + 10;
const double EPS = 1e-8;

double add(double a, double b) {
    if (abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
    return a + b;
} 
struct P {
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y) {}
    P operator + (P p) {
        return P(add(x, p.x), add(y, p.y));
    }
    P operator - (P p) {
        return P(add(x, -p.x), add(y, -p.y));
    }
    P operator * (double d) {
        return P(x * d, y * d);
    }
    double dot(P p) { // 内积
        return add(x * p.x, y * p.y);
    }
    double det(P p) { // 外积
        return add(x * p.y, -y * p.x);
    }
};
bool on_seg(P p1, P p2, P q) {
    return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}
P intersection(P p1, P p2, P q1, P q2) {
    return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

int n, m;
P p[MAX_N], q[MAX_N];
bool g[MAX_N][MAX_N];

void solve() {
    rep(i, 0, n) {
        g[i][i] = true;
        rep(j, 0, i) {
            if ((p[i] - q[i]).det(p[j] - q[j]) == 0) {
                g[i][j] = g[j][i] = on_seg(p[i], q[i], p[j])
                                 || on_seg(p[i], q[i], q[j])
                                 || on_seg(p[j], q[j], p[i])
                                 || on_seg(p[j], q[j], q[i]);
            }
            else {
                P r = intersection(p[i], q[i], p[j], q[j]);
                g[i][j] = g[j][i] = on_seg(p[i], q[i], r) && on_seg(p[j], q[j], r);
            }
        }
    }
    rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)
        g[i][j] |= g[i][k] & g[k][j];
}

int main(int argc, char const *argv[])
{
    while (scanf("%d", &n) && n) {
        int x1, x2, y1, y2;
        rep(i, 0, n) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            p[i] = P(x1, y1); q[i] = P(x2, y2);
        }
        solve();
        int a, b;
        while (scanf("%d%d", &a, &b) && a + b) {
            --a; --b;
            puts(g[a][b]? "CONNECTED" : "NOT CONNECTED ");
        }
    }    
    return 0;
}