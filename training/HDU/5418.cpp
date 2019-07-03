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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 20;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, N, M, W[MAX_N][MAX_N], dp[1 << MAX_N][MAX_N];

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (i == j) W[i][j] = 0;
                else W[i][j] = INF / 3;
        for (int i = 0; i < M; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w); --u; --v;
            W[u][v] = W[v][u] = min(W[u][v], w);
        }
        
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                for (int k = 0; k < N; ++k)
                    W[i][j] = W[j][i] = min(W[i][j], W[i][k] + W[k][j]);

        // for (int i = 0; i < N; ++i, puts(""))
        //     for (int j = 0; j < N; ++j)
        //         cout << W[i][j] << " ";
        
        for (int S = 0; S < 1 << N; ++S)
            fill(dp[S], dp[S] + N, INF / 3);
        
        dp[(1 << N) - 1][0] = 0;
        
        for (int S = (1 << N) - 2; S >= 0; S--)
            for (int v = 0; v < N; ++v)
                for (int u = 0; u < N; ++u)
                    if (!(S >> u &1)) 
                        dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + W[v][u]);
        int ans = INF;
        for (int i = 0; i < N; ++i)
            ans = min(ans, dp[0][i] + W[i][0]);
        printf("%d\n", ans); 
    }   
    return 0;
}