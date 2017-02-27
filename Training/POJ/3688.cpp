// written at 15:12 on 26 Feb 2017 
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

int N, M, A[MAX_N];
bool dp[MAX_N][2];

int main(int argc, char const *argv[])
{
    while(scanf("%d%d", &N, &M), N + M) {
        memset(dp, false, sizeof dp);
        rep(i, 0, N) scanf("%d", A + i);
        dp[0][0] = true;
        rep(i, 0, N) irep(j, M + 1, A[i])
            rep(k, 0, 2) dp[j][k] |= dp[j - A[i]][!k];
        int res = 0;
        rep(i, 1, M + 1) if (dp[i][1] && !dp[i][0]) ++res;
        printf("%d\n", res);
    }
    return 0;
}