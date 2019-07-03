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
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > dl;;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1000 + 10;
const int MAX_K = 100 + 10;
const ull MOD = 100000000000000000;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, K;
ull dp[MAX_K][MAX_N][2];

int main(int argc, char const *argv[])
{
    cin >> N >> K;
    for (int i = 1; i <= K; ++i) {
        dp[i][0][1] = 1;
        for (int j = 1; j <= N; ++j)
            if (j < i) {
                dp[i][j][0] = dp[i - 1][j][0];
                dp[i][j][1] = dp[i - 1][j][1];
            } else {
                dp[i][j][0] = dp[i][j - i][0] + dp[i - 1][j][0];
                dp[i][j][1] = dp[i][j - i][1] + dp[i - 1][j][1];
                dp[i][j][0] += dp[i][j][1] / MOD;
                dp[i][j][1] = dp[i][j][1] % MOD;
            }
    }
    if (dp[K][N][0]) cout << dp[K][N][0];
    cout << dp[K][N][1] << endl;
    return 0;
}