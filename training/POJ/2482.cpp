// written at 11:43 on 10 Feb 2017 
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
const int MAX_N = 1e4 + 10;

int N, W, H, C[MAX_N], ans, M;
ll X[MAX_N], Y[MAX_N], xc[2 * MAX_N], yc[2 * MAX_N];
int dat[8 * MAX_N], n;
pair<Pii, Pii > xs[2 * MAX_N];

void init(int N) {
    n = 1 << (32 - __builtin_clz(N));
    rep(i, 0, n) dat[i] = 0;
}
int update(int a, int b, int k, int l, int r, int c) {
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) {
        if (dat[k] == -1) {
            int lm = update(a, b, 2 * k + 1, l, (l + r) / 2, c);
            int rm = update(a, b, 2 * k + 2, (l + r) / 2, r, c);
            return max(lm, rm);
        } else return dat[k] += c;
    } else {
        if (dat[k] != -1) {
            dat[2 * k + 1] = dat[2 * k + 2] = dat[k];
            dat[k] = -1;
        }
        int lm = update(a, b, 2 * k + 1, l, (l + r) / 2, c);
        int rm = update(a, b, 2 * k + 2, (l + r) / 2, r, c);
        return max(lm, rm);
    }
}

int compress() {
    rep(i, 0, N) {
        xc[2 * i] = X[i] - W; xc[2 * i + 1] = X[i] + W;
        yc[2 * i] = Y[i] - H; yc[2 * i + 1] = Y[i] + H;
    }
    sort(xc, xc + 2 * N); sort(yc, yc + 2 * N);
    int mx = 1, my = 1;
    rep(i, 0, 2 * N) {
        if (xc[i] != xc[mx - 1]) xc[mx++] = xc[i];
        if (yc[i] != yc[my - 1]) yc[my++] = yc[i];
    }
    int res = 0;
    rep(i, 0, N) {
        int x1, x2, y1, y2;
        x1 = lower_bound(xc, xc + mx, X[i] - W) - xc;
        x2 = lower_bound(xc, xc + mx, X[i] + W) - xc;
        y1 = lower_bound(yc, yc + my, Y[i] - H) - yc;
        y2 = lower_bound(yc, yc + my, Y[i] + H) - yc;
        // cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
        res = max(res, y1), res = max(res, y2);

        xs[2 * i] = make_pair(Pii(x1, C[i]), Pii(y1, y2));
        xs[2 * i + 1] = make_pair(Pii(x2, -C[i]), Pii(y1, y2));
    }
    return res;
}

void solve() {
    M = compress();
    sort(xs, xs + 2 * N);
    init(M);
    ans = 0;
    rep(i, 0, 2 * N)
        ans = max(ans, update(xs[i].second.first, xs[i].second.second, 0, 0, n, xs[i].first.second));
    printf("%d\n", ans);
}

int main(int argc, char const *argv[])
{
    while (~scanf("%d%d%d", &N, &W, &H)) {
        rep(i, 0, N) {
            scanf("%lld%lld%d", X + i, Y + i, C + i);
            X[i] *= 2; Y[i] *= 2;
        }
        solve();
    }    
    return 0;
}