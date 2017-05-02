// written at 18:11 on 12 Feb 2017 
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
const int MAX_N = 2e2 + 10;
const double EPS = 1e-10;

int W, H, N;
double X[MAX_N], Y[MAX_N], th[MAX_N];

int main(int argc, char const *argv[])
{
    while (scanf("%d%d%d", &W, &H, &N), N) {
        rep(i, 0, 2 * N) scanf("%lf%lf", X + i, Y + i);
        X[2 * N] = W; Y[2 * N] = 0;
        X[2 * N + 1] = W; Y[2 * N + 1] = H;
        vector<double> v;
        rep(i, 0, 2 * N + 2) rep(j, i + 1, 2 * N + 2) {
            if (fabs(X[i] - X[j]) < EPS) continue;
            double tmp = Y[i] - X[i] * (Y[i] - Y[j]) / (X[i] - X[j]);
            if (tmp < 0 || tmp > H) continue;
            v.push_back(tmp);
        }
        v.push_back(0); v.push_back(H);
        sort(v.begin(), v.end());
        double ret = 0;
        rep(i, 0, v.size() - 1) {
            if (v[i + 1] - v[i] < EPS) continue;
            double mid = (v[i] + v[i + 1]) / 2;
            rep(j, 0, 2 * N + 2) th[j] = atan2(Y[j] - mid, X[j]);
            sort(th, th + 2 * N + 2);
            double L = max(0., mid + W * tan(th[N]));
            double R = min((double)H, mid + W * tan(th[N + 1]));
            ret += max(0.0, R - L) * (v[i + 1] - v[i]);
        }
        printf("%.12f\n", ret / H / H);
    }
    return 0;
}

