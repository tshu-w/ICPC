// written at 13:52 on 8 Feb 2017 
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
const int MAX_N = 1e2;
const double g = 9.8;
const double EPS = 1e-10;

int N, V, X, Y;
int L[MAX_N], B[MAX_N], R[MAX_N], T[MAX_N];

double calc(double vy, double t) {
    return vy * t - g * sqr(t) / 2;
}
int cmp(double lb, double ub, double a) {
    return a < lb + EPS ? -1 : a > ub - EPS ? 1 : 0;
}

bool check(double qx, double qy) {
    double a = sqr(g) / 4, b = g * qy - sqr(V), c = sqr(qx) + sqr(qy);
    double D = sqr(b) - 4 * a * c;
    if (D < 0 && D > -EPS) D = 0;
    if (D < 0) return false;
    for (int d = -1; d <= 1; d += 2) {
        double t2 = (-b + d * sqrt(D)) / (2 * a);
        if (t2 <= 0) continue;
        double t = sqrt(t2);
        double vx = qx / t, vy = (qy + g * sqr(t) / 2) / t;

        double yt = calc(vy, X / vx);
        if (yt < Y - EPS) continue;

        bool ok = true;
        rep(i, 0, N) {
            if (L[i] >= X) continue;
            if (R[i] == X && Y <= T[i] && B[i] <= yt) ok = false;
            int yL = cmp(B[i], T[i], calc(vy, L[i] / vx));
            int yR = cmp(B[i], T[i], calc(vy, R[i] / vx));
            int xH = cmp(L[i], R[i], vx * (vy / g));
            int yH = cmp(B[i], T[i], calc(vy, vy / g));
            if (xH == 0 && yH >= 0 && yL < 0) ok = false;
            if (yL * yR <= 0) ok = false;
        }
        if (ok) return true;
    }
    return false;
}

void solve() {
    rep(i, 0, N) R[i] = min(R[i], X);
    bool ok = check(X, Y);
    rep(i, 0, N) {
        ok |= check(L[i], T[i]);
        ok |= check(R[i], T[i]);
    }
    puts(ok ? "Yes" : "No");
}
int main(int argc, char const *argv[])
{
    scanf("%d%d%d%d", &N, &V, &X, &Y);
    rep(i, 0, N) scanf("%d%d%d%d", L + i, B + i, R + i, T + i);
    solve();
    return 0;
}