// written at 15:17 on 8 Feb 2017 
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
typedef pair<double, int > Pdi;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 300 + 10;
const double R = 1.0;

int N;
double X[MAX_N], Y[MAX_N];
Pdi as[MAX_N];

double dis(int i, int j) {
    return sqrt(sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]));
}

void solve() {
    int res = 1;
    rep(i, 0, N) {
        int m = 0, sum = 1;
        double d;
        rep(j, 0, N) if (i != j && (d = dis(i, j)) <= 2) {
            double phi = acos(d / 2);
            double theta = atan2(Y[j] - Y[i], X[j] - X[i]);
            as[m].first = theta - phi, as[m++].second = 0;
            as[m].first = theta + phi, as[m++].second = 1;
        }
        sort(as, as + m);
        rep(j, 0, m) {
            if (as[j].second) --sum; else ++sum;
            res = max(sum, res);
        }
    }
    printf("%d\n", res);
}

int main(int argc, char const *argv[])
{
    while (scanf("%d", &N) && N) {
        int ans = 1;
        rep(i, 0, N) scanf("%lf%lf", X + i, Y + i);
        solve();
    }    
    return 0;
}