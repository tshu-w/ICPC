// written at 17:44 on 12 Feb 2017 
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
const double INF = DBL_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e2 + 10;

int M, N;
int X1[MAX_N], Y1[MAX_N], X2[MAX_N], Z2[MAX_N];

double width(int *X, int *Y, int n, double x) {
    double lb = INF, ub = -INF;
    rep(i, 0, n) {
        double x1 = X[i], y1 = Y[i], x2 = X[(i + 1) % n], y2 = Y[(i + 1) % n];
        if ((x1 - x) * (x2 - x) <= 0 && x1 != x2) {
            double y = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
            lb = min(lb, y); ub = max(ub, y);
        }
    }
    return max(0.0, ub - lb);
}

void solve() {
    int min1 = *min_element(X1, X1 + M), max1 = *max_element(X1, X1 + M);
    int min2 = *min_element(X2, X2 + N), max2 = *max_element(X2, X2 + N);
    vector<int> xs;
    rep(i, 0, M) xs.push_back(X1[i]);
    rep(i, 0, N) xs.push_back(X2[i]);
    sort(xs.begin(), xs.end());

    double res = 0;
    rep(i, 0, xs.size() - 1) {
        double a = xs[i], b = xs[i + 1], c = (a + b) / 2;
        if (min1 <= c && c <= max1 && min2 <= c && c <= max2) {
            double fa = width(X1, Y1, M, a) * width(X2, Z2, N, a);
            double fb = width(X1, Y1, M, b) * width(X2, Z2, N, b);
            double fc = width(X1, Y1, M, c) * width(X2, Z2, N, c);
            res += (b - a) / 6 * (fa + 4 * fc + fb);
        }
    }
    printf("%.10f\n", res);
}

int main(int argc, char const *argv[])
{
    while (scanf("%d%d", &M, &N) && M + N) {
        rep(i, 0, M) scanf("%d%d", X1 + i, Y1 + i);
        rep(i, 0, N) scanf("%d%d", X2 + i, Z2 + i);
        solve();
    }
    return 0;
}

