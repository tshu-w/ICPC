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
const int MAX_N = 1e6 + 10;
const int MOD = 1e9;

template <typename T>
inline T sqr(T a) { return a * a;};

int N;
ll dp[MAX_N];

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    dp[1] = 1;;
    for (int i = 2; i <= N; ++i)    
        if (i & 1) dp[i] = dp[i - 1];
        else dp[i] = (dp[i - 1] + dp[i / 2]) % MOD;
    printf("%lld\n", dp[N] % MOD);
    return 0;
}