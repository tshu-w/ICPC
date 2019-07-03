// written at 11:16 on 26 Feb 2017 
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
const int MAX_S = 1e5 + 10;
const int MAX_N = 20 + 5;

int N, S, M[MAX_N];
bool dp[MAX_S][MAX_N];

int main(int argc, char const *argv[])
{
    while (cin >> N >> S, N) {
        rep(i, 0, 2 * N) cin >> M[i];
        memset(dp, false, sizeof dp);
        rep(i, 0, 2 * N) dp[0][i] = true;
        rep(i, 1, S + 1) {
            rep(j, 0, 2 * N)
                rep(k, 1, min(M[j], i) + 1) dp[i][j] |= !dp[i - k][(j + 1) % (2 * N)];
        }
        cout << dp[S][0] << endl;
    }
    return 0;
}