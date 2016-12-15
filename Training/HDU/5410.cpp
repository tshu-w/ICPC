#include <bits/stdc++.h>

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
const int MAX_N = 1000 + 10;
const int MAX_W = 2000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, N, M, A[MAX_N], B[MAX_N], W[MAX_N], dp[MAX_W];

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &M, &N);
        for (int i = 0; i < N; ++i) 
            scanf("%d%d%d", W + i, A + i, B + i);

        memset(dp, 0, sizeof dp);
        for (int i = 0; i < N; ++i) {
            for (int j = M; j >= W[i]; --j)
                dp[j] = max(dp[j], dp[j - W[i]] + A[i] + B[i]);
            for (int j = W[i]; j <= M; ++j)
                dp[j] = max(dp[j], dp[j - W[i]] + A[i]);
        }
        int ans = 0;
        for (int i = 0; i <= M; ++i)
            ans = max(ans, dp[i]);
        printf("%d\n", ans);
    }    
    return 0;
}