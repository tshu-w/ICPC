// written at 10:06 on 11 Feb 2017 
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
#define filename "3068"
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
const double EPS = 1e-10;
inline int sgn(double x) {
    return (x > EPS) - (x < -EPS);
}

struct P
{
    double x, y;
    inline void read() { scanf("%lf%lf", &x, &y); }
    inline void write() { printf("(%f, %f)\n", x, y); }
    P(double x = 0, double y = 0) : x(x), y(y) {}
    P operator + (P p) { return P(x + p.x, y + p.y); }    
    P operator - (P p) { return P(x - p.x, y - p.y); }
    double dot(P p) { return x * p.x + y * p.y; }
    double det(P p) { return x * p.y - y * p.x; }
    bool operator < (const P & p) const {
        return (x == p.x)? y < p.y : x < p.x;
    }
} ps[MAX_N], qs[MAX_N];

int N, M;

inline double dist(P a, P b) {
    return sqrt((a - b).dot(a - b));
}
inline double dist(P a, P b, P c) {
    if ((a - b).dot(a - c) * (b - a).dot(b - c) < 0) 
        return min(dist(a, c), dist(b, c));
    return fabs((b - a).det(c - a)) / dist(a, b);
}
inline double dist(P a, P b, P c, P d) {
    return min(min(dist(a, b, c), dist(a, b, d)), min(dist(c, d, a), dist(c, d, b)));
}

int convex_hull(P * p, int n) {
    sort(p, p + n);
    vector<P> q(2 * n);
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
    rep(i, 0, k) p[i] = q[i]; if (k) p[k] = p[0];
    return k - 1;
}

void solve() {
    int i = 0, j = 0;
    rep(k, 0, N) if (ps[i].y > ps[k].y) i = k;
    rep(k, 0, M) if (qs[j].y < qs[k].y) j = k;
    double ans = INF;
    rep(k, 0, N) {
        ans = min(ans, dist(ps[i], ps[i + 1], qs[j], qs[j + 1]));
        while ((ps[i + 1] - ps[i]).det(qs[j + 1] - qs[j]) > 0) {
            j = (j + 1) % M;
            ans = min(ans, dist(ps[i], ps[i + 1], qs[j], qs[j + 1]));
        }
        i = (i + 1) % N;
    }
    printf("%.5f\n", ans);
}

int main(int argc, char const *argv[])
{
    while (~scanf("%d%d", &N, &M) && N + M) {
        rep(i, 0, N) ps[i].read();
        rep(j, 0, M) qs[j].read();
        N = convex_hull(ps, N); M = convex_hull(qs, M);
        solve();
    }
    return 0;
}