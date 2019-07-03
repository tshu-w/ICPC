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
const int MAX_N = 10;
const int MAX_W = 100 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, C1, C2, W[MAX_N], dp[(1 << MAX_N) + 5], cases = 0;

bool check(int S) {
    bool flag[MAX_W];
    int sum = 0;
    memset(flag, 0, sizeof flag);
    flag[0] = 1;
    for (int i = 0; i < N; ++i)
        if (S >> i & 1) {
            sum += W[i];
            for (int j = C1; j >= W[i]; --j)
                flag[j] |= flag[j - W[i]];
        }
    for (int i = C1; i >= 0; --i)
        if (flag[i] && sum - i <= C2)
            return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &N, &C1, &C2);
        if (C1 > C2) swap(C1, C2);
        for (int i = 0; i < N; ++i)
            scanf("%d", W + i);
        
        vector<int> v;
        for (int i = 1; i < 1 << N; ++i)
            if (check(i))
                v.push_back(i);
        
        // for (auto x : v)
        //     cout << x << endl;
        
        for (int i = 1; i < 1 << N; ++i)
            dp[i] = INF;
        dp[0] = 0;
        for (int i = 0; i < v.size(); ++i)
            for (int j = (1 << N) - 1 - v[i]; j >= 0; j--)
                if (!(j & v[i]) && dp[j] != INF)
                    dp[j | v[i]] = min(dp[j] + 1, dp[j | v[i]]);
        printf("Scenario #%d:\n%d\n\n", ++cases, dp[(1 << N) - 1]);
    }    
    return 0;
}