// written at 11:54 on 26 Apr 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename "C-large-practice"
#define setfile() freopen(filename".in.txt", "r", stdin); freopen(filename".ans.txt", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans.txt");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 100 + 10;

int t, n, q, S[MAX_N], E[MAX_N], G[MAX_N][MAX_N];
double cost[MAX_N][MAX_N];

void dis_floyd() {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] = min(G[i][k] + G[k][j], G[i][j]);
}

void cost_floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (E[i] >= G[i][k]) cost[i][k] = min((double)G[i][k] / S[i], cost[i][k]);
                if (E[k] >= G[k][j]) cost[k][j] = min((double)G[k][j] / S[k], cost[k][j]);
                cost[i][j] = min(cost[i][k] + cost[k][j], cost[i][j]);
            }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++)
        //         if (cost[i][j] == DBL_MAX / 3) printf("%8.2f", -1.);
        //         else printf("%8.2f", cost[i][j]);
        //     cout << endl;
        // }
        // cout << endl;
    }
}

int main(void)
{
    setfile();
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> n >> q;
        for (int i = 0; i < n; i++)
            cin >> E[i] >> S[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> G[i][j];
                if (G[i][j] == -1) G[i][j] = INT_MAX / 2;
                if (i == j) {
                    G[i][j] = 0;
                    cost[i][j] = 0;
                } else
                    cost[i][j] = DBL_MAX / 3;
            }
        dis_floyd();
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++)
        //         if (G[i][j] == INT_MAX / 2) cout << -1 << " ";
        //         else cout << G[i][j] << " ";
        //     cout << endl;
        // }
        cost_floyd();
        printf("Case #%d:", _ + 1);
        for (int i = 0; i < q; i++) {
            int v, u;
            cin >> v >> u; --v, --u;
            printf(" %f", cost[v][u]);
        }
        printf("\n");
    }
    resetfile();
    return 0;
}
