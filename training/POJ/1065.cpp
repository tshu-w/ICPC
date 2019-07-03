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
const int MAX_N = 5000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, N, dp[MAX_N];
Pii W[MAX_N];

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            scanf("%d%d", &W[i].first, &W[i].second);
        sort(W, W + N);
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < N; ++i)
            *lower_bound(dp, dp + N, W[i].second, greater<int>()) = W[i].second;
        printf("%d\n", lower_bound(dp, dp + N, 0, greater<int>()) - dp);
    }
    return 0;
}