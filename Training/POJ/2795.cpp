// written at 08:30 on 27 Feb 2017 
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
const int MAX_N = 1e3 + 10;

int N, A[MAX_N], f[MAX_N];

int solve() {
    int x = 0;
    rep(i, 0, N) x ^= A[i];
    int ans = 0;
    rep(i, 0, N) if ((x ^ A[i]) < A[i]) ++ans;
    printf("%d\n", ans);
    // memset(f, -1, sizeof f);
    // int cnt = 0;
    // while (cnt < N) {
    //     int res = 0;
    //     for (int i = 0; i < N; ++i)
    //         if (A[i] & 1) ++res;
    //     for (int i = 0; i < N; ++i) {
    //         if (res & 1) {
    //             if (f[i] == -1) f[i] = A[i] & 1;
    //             else f[i] &= A[i] & 1;
    //         }
    //         if (A[i] != 0 && A[i] / 2 == 0) ++cnt;
    //         A[i] >>= 1;
    //     }
    // }
    return 0;
}

int main(int argc, char const *argv[])
{    while(scanf("%d", &N), N) {
        rep(i, 0, N) scanf("%d", A + i);
        solve();
    } 
    return 0;
}