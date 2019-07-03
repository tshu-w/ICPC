// written at 09:04 on 21 Feb 2017 
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
const int MAX_N = 1e3 + 10;
const int MAX_M = 1e4 + 10;

int k, q, p;
double dp[MAX_N][MAX_M];

int main(int argc, char const *argv[])
{
    scanf("%d%d", &k, &q);
    dp[0][0] = 1;
    rep(i, 1, MAX_M) rep(j, 1, k + 1) 
        dp[j][i] = dp[j][i - 1] * (double) j / k + dp[j - 1][i - 1]* (double)(k - j + 1) / k;
    rep(i, 0, q) {
        scanf("%d", &p);
        double d = (p - 1e-7) / 2000.;
        printf("%d\n", (int)(lower_bound(dp[k], dp[k] + MAX_M, d) - dp[k]));
    }
    return 0;
}