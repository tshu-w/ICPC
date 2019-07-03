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
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1000 + 10;
const int MAX_A = 1e5 + 10;
const int MOD = 1000000;

template <typename T>
inline T sqr(T a) { return a * a;};

int T, A, S, B, dp[MAX_N][MAX_A], n[MAX_N];

int main(int argc, char const *argv[])
{
    scanf("%d%d%d%d", &T, &A, &S, &B);
    for (int i = 0, a; i < A; ++i) {
        scanf("%d", &a);
        ++n[a - 1];
    }
    for (int i = 0; i <= T; ++i)
        dp[i][0] = 1;
    for (int i = 0; i < T; ++i)
        for (int j = 1; j <= A; ++j)    
            if (j - 1 - n[i] >= 0) 
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - n[i]] + MOD) % MOD;
            else dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;    
    ll ans = 0;
    for (int i = S; i <= B; ++i)
        ans = (ans + dp[T][i]) % MOD;
    printf("%lld\n", ans);
    return 0;
}