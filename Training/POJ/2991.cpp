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

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e4 + 10;
const int ST_SIZE = (1 << 15) - 1;

int N, C, L[MAX_N], s, A;

double vx[ST_SIZE], vy[ST_SIZE], ang[ST_SIZE], pre[MAX_N];

void init(int k, int l, int r) {
    vx[k] = ang[k] = 0.;
    if (l + 1 == r) {
        vy[k] = L[l];
    } else {
        init(2 * k + 1, l, (l + r) / 2);
        init(2 * k + 2, (l + r) / 2, r);
        vy[k] = vy[2 * k + 1] + vy[2 * k + 2];
    }
}

void change(int s, double a, int k, int l, int r) {
    if (l + 1 == r) return;
    if (s < l) return;
    else if (s < r) {
        int ch1 = 2 * k + 1, ch2 = 2 * k + 2, m = (l + r) / 2;
        change(s, a, ch1, l, m);
        change(s, a, ch2, m, r);
        if (s < m) ang[k] += a;
        double s = sin(ang[k]), c = cos(ang[k]);
        vx[k] = vx[ch1] + vx[ch2] * c - vy[ch2] * s;
        vy[k] = vy[ch1] + vx[ch2] * s + vy[ch2] * c;
    }
}

int main(int argc, char const *argv[])
{
    bool flag = false;
    while(~scanf("%d%d", &N, &C)) {
        for (int i = 0; i < N; ++i)
            scanf("%d", L + i), pre[i] = pi;
        if (flag) printf("\n"); else flag = true;
        init(0, 0, N);
        for (int i = 0; i < C; ++i) {
            scanf("%d%d", &s, &A); --s;
            double a = A / 180. * pi;
            change(s, a - pre[s], 0, 0, N);
            pre[s] = a;
            printf("%.3f %.3f\n", vx[0], vy[0]);
        }
    }
    return 0;
}