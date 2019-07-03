// written at 18:02 on 11 Feb 2017 
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

struct P
{
    double x, y;
    void read() { scanf("%lf%lf", &x, &y); }
    void write() { printf("(%lf, %lf)\n", x, y);}
    P(double x = 0, double y = 0) : x(x), y(y) {}
    P operator + (P p) { return P(x + p.x, y + p.y); }
    P operator - (P p) { return P(x - p.x, y - p.y); }
    double dot(P p) { return x * p.x + y * p.y; }
    double det(P p) { return x * p.y - y * p.x; }
    bool operator < (const P &p) const {
        return (x == p.x)? y < p.y : x < p.x;
    }
}ps[MAX_N];

int N;

int convex_hull(P p[], int n) {
    sort(p, p + n);
    vector<P> tmp(2 * n);
    int k = 0;
    rep(i, 0, n) {
        while (k > 1 && (tmp[k - 1] - tmp[k - 2]).det(p[i] - tmp[k - 1]) <= 0) --k;
        tmp[k++] = ps[i];
    }
    int t = k;
    irep(i, n - 1, 0) {
        while (k > t && (tmp[k - 1] - tmp[k - 2]).det(p[i] - tmp[k - 1]) <= 0) --k;
        tmp[k++] = ps[i];
    }
    rep(i, 0, k - 1) p[i] = tmp[i]; p[k - 1] = p[0];
    return k - 1;
}

void solve() {
    N = convex_hull(ps, N);
    double ans = 0;
    rep(i, 0, N) {
        int k = 2;
        rep(j, i + 1, N) {
            while ((ps[j] - ps[i]).det(ps[k] - ps[i]) < (ps[j] - ps[i]).det(ps[k + 1] - ps[i])) k = (k + 1) % N;
            ans = max(ans, (ps[j] - ps[i]).det(ps[k] - ps[i]) / 2.);
        }
    }
    printf("%.2f\n", ans);
}

int main(int argc, char const *argv[])
{
    while (~scanf("%d", &N) && N > 0) {
        rep(i, 0, N) ps[i].read();
        solve();
    }
    return 0;
}