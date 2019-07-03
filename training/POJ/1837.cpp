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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 20 + 5;
const int gap = 7500;

template <typename T>
inline T sqr(T a) { return a * a;};

int C, G, X[MAX_N], W[MAX_N], dp[MAX_N][2 * gap + 10];

int main(int argc, char const *argv[])
{
    scanf("%d%d", &C, &G);
    for (int i = 1; i <= C; ++i)
        scanf("%d", X + i);
    for (int i = 1; i <= G; ++i)
        scanf("%d", W + i);
    memset(dp, 0, sizeof dp);
    dp[0][gap] = 1;
    for (int i = 1; i <= G; ++i)
        for (int j = 1; j <= C; ++j)
            for (int k = 0; k <= 2 * gap; ++k)
                if (W[i] * X[j] + k >= 0 && W[i] * X[j] + k <= 2 * gap && dp[i - 1][k])
                    dp[i][W[i] * X[j] + k ] += dp[i - 1][k];
    cout << dp[G][gap];    
    return 0;
}