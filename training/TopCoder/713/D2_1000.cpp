// written at 14:33 on 29 Apr 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 15;

int id[MAX_N], n;
ll dp[1 << MAX_N][MAX_N], pw[MAX_N], pol[MAX_N];
bool vis[MAX_N], g[MAX_N][MAX_N];

class DFSCountEasy
{
public:
    long long count(vector <string> G) {
        n = G.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = G[i][j] == 'Y';
        pw[0] = 1;
        for (int i = 1; i < MAX_N; i++)
            pw[i] = pw[i - 1] * i;
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < 1 << n; i++)
            dp[(1 << n) - 1][i] = 1;

        for (int S = (1 << n) - 2; S > 0; S--) {
            for (int i = 0; i < n; i++)
                if (S >> i & 1) {
                    for (int j = 0; j < n; j++)
                        vis[j] = S >> j & 1;

                    int cnt = 0;
                    for (int j = 0; j < n; j++) {
                        if (g[i][j] && !(S >> j & 1)) {
                            if (!vis[j]) {
                                dfs(j, ++cnt);
                                pol[cnt] = 0;
                            }
                            pol[id[j]] += dp[1 << j | S][j];
                        }
                    }
                    dp[S][i] = pw[cnt];
                    for (int k = 1; k <= cnt; k++)
                        dp[S][i] *= pol[k];
                }
        }

        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans += dp[1 << i][i];
        return ans;
    }

private:
    void dfs(int v, int ID) {
        id[v] =  ID;
        vis[v] = true;
        for (int u = 0; u < n; u++) {
            if (g[v][u] && !vis[u])
                dfs(u, ID);
        }
    }
};

int main(void)
{
    DFSCountEasy test;
    vector<string> G;
    G.push_back("NYYY");
    G.push_back("YNYY");
    G.push_back("YYNN");
    G.push_back("YYNN");
    cout << test.count(G) << endl;
    return 0;
}
