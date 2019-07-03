#include <bits/stdc++.h>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e5 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

vector<int> g[MAX_N];

int mu[MAX_N], val[MAX_N], cnt[MAX_N], sz[MAX_N], ans[MAX_N], prime[MAX_N];
bool vis[MAX_N];
vector<int> factors[MAX_N];
void moebius() {
    int cnt = 0; mu[1] = 1;
    for (int i = 2; i < MAX_N; ++i) {
        if (!vis[i]) {
            prime[cnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < cnt && prime[j] * i < MAX_N; ++j) {
            vis[prime[j] * i] = 1;
            if (i % prime[j]) 
                mu[i * prime[j]] = -mu[i];
            else {
                mu[i * prime[j]] = 0; break;
            }
        }
    }

    for (int i = 2; i < MAX_N; ++i) if (mu[i]) 
        for (int j = i; j < MAX_N; j += i) 
            factors[j].push_back(i);
}
void dfs(int u, int fa) {
    sz[u] = 1;
    vector<int> pre;
    for (int i = 0; i < factors[val[u]].size(); ++i) {
        int d = factors[val[u]][i];
        pre.push_back(cnt[d]++);
    }

    for (int i = 0; i < g[u].size(); ++i) if (g[u][i] != fa){
        int v = g[u][i];
        dfs(v, u);
        sz[u] += sz[v];
    }
    ans[u] = sz[u];

    for (int i = 0; i < factors[val[u]].size(); ++i) {
        int d = factors[val[u]][i];
        ans[u] += mu[d] * (cnt[d] - pre[i]);
    }
}
int main(int argc, char const *argv[])
{
    int t = 0, n;
    moebius();
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i)
            g[i].clear();
        for (int u, v, i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i)
            scanf("%d", &val[i]);
        memset(cnt, 0, sizeof cnt);
        memset(sz, 0, sizeof sz);
        memset(ans, 0, sizeof ans);

        dfs(1, 0);

        printf("Case #%d:", ++t);
        for (int i = 1; i <= n; ++i)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}