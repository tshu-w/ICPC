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
const int MAX_N = 100 + 10;
const int MAX_M = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, N, M, W[MAX_N], V[MAX_N], K, dp[MAX_M];

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        memset(dp, 0, sizeof dp);
        scanf("%d%d", &N, &M);
        for (int k = 0; k < N; ++k) {
            scanf("%d", &K);
            for (int i = 0; i < K; ++i)
                scanf("%d%d", W + i, V + i);
            for (int j = M; j >= 0; --j)
                for (int i = 0; i < K; ++i)
                    if (j - W[i] >= 0)
                        dp[j] = max(dp[j - W[i]] + V[i], dp[j]);
            // for (int i = 0; i < M; ++i)
            //     cout << dp[i] << " ";
            // cout << endl;
        }
        int ans = 0;
        for (int i = 0; i <= M; ++i)
            ans = max(ans, dp[i]);
        printf("%d\n", ans);
    }    
    return 0;
}