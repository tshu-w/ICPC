// written at 13:47 on 27 Feb 2017 
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
#include <numeric>

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
const int MAX_N = 40 + 10;

int N, M, sg[MAX_N][MAX_N][MAX_N][MAX_N][2];
char s[MAX_N][MAX_N];

int grundy(int l, int r, int d, int u, int k) {
    if (sg[l][r][d][u][k] != -1) return sg[l][r][d][u][k];
    ll c = 0;
    rep(i, 0, N) rep(j, 0, M) if (((i + j) & 1) == k) {
        int p = i + j, q = N - i + j, res;
        if (l <= p && p < r && d <= q && q < u) {
            if (s[i][j] == 'L') res = grundy(l, p, d, u, k) ^ grundy(p + 1, r, d, u, k);
            else if (s[i][j] == 'R') res = grundy(l, r, d, q, k) ^ grundy(l, r, q + 1, u, k);
            else res = grundy(l, p, d, q, k) ^ grundy(l, p, q + 1, u, k) ^ grundy(p + 1, r, d, q, k) ^ grundy(p + 1, r, q + 1, u, k);
            c |= 1ll << res;
        }
    }
    return sg[l][r][d][u][k] = __builtin_ctzll(++c);
}

int main(int argc, char const *argv[])
{
    cin >> N >> M;
    rep(i, 0, N) scanf("%s", s[i]);
    memset(sg, -1, sizeof sg);
    puts(grundy(0, N + M, 0, N + M, 0) ^ grundy(0, N + M, 0, N + M, 1) ? "WIN" : "LOSE");
    return 0;
}