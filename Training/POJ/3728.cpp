// written at 09:33 on 5 Mar 2017 
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
#include <numeric>

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

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_V = 1e5 + 10;
const int MAX_LOG_V = 20;

int V, A[MAX_V], Q;
vector<int> G[MAX_V];
int parent[MAX_LOG_V][MAX_V], depth[MAX_V];

int dp_max[MAX_LOG_V][MAX_V], dp_min[MAX_LOG_V][MAX_V];
int dp_up[MAX_LOG_V][MAX_V], dp_down[MAX_LOG_V][MAX_V];

void dfs(int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    if (p != -1) {
        dp_max[0][v] = max(A[v], A[p]);
        dp_min[0][v] = min(A[v], A[p]);
        dp_up[0][v] = max(0, A[p] - A[v]);
        dp_down[0][v] = max(0, A[v] - A[p]);
    }
    for (int i = 0; i < G[v].size(); i++)
        if (G[v][i] != p)
            dfs(G[v][i], v, d + 1);
}
void init(int V) {
    memset(dp_max, 0, sizeof dp_max);
    memset(dp_min, 0x3f, sizeof dp_min);
    dfs(0, -1, 0);   
    for (int k = 0; k + 1 < MAX_LOG_V; k++)
        for (int v = 0; v < V; v++)
            if (parent[k][v] < 0) parent[k + 1][v] = -1;
            else {
                int u = parent[k][v];
                parent[k + 1][v] = parent[k][u];
                dp_max[k + 1][v] = max(dp_max[k][v], dp_max[k][u]);
                dp_min[k + 1][v] = min(dp_min[k][v], dp_min[k][u]);
                dp_up[k + 1][v] = max(max(dp_up[k][v], dp_up[k][u]), dp_max[k][u] - dp_min[k][v]);
                dp_down[k + 1][v]= max(max(dp_down[k][v], dp_down[k][u]), dp_max[k][v] - dp_min[k][u]);
            }
}
int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < MAX_LOG_V; k++)
        if ((depth[v] - depth[u]) >> k & 1)
            v = parent[k][v];
    if (u == v) return u;
    for (int k = MAX_LOG_V - 1; k >= 0; k--)
        if (parent[k][v] != parent[k][u]) {
            v = parent[k][v];
            u = parent[k][u];
        }
    return parent[0][u];
}

int up(int v, int s, int &imin) {
    imin = INF;
    int res = 0, pre_min = INF;
    for (int k = MAX_LOG_V - 1; k >= 0; k--)
        if (s >> k & 1) {
            imin = min(imin, dp_min[k][v]);
            res = max(res, dp_up[k][v]);
            res = max(res, dp_max[k][v] - pre_min);
            pre_min = min(pre_min, dp_min[k][v]);
            v = parent[k][v];
        }
    return res;
}

int down(int v, int s, int &imax) {
    imax = 0;
    int res = 0, pre_max = 0;
    for (int k = MAX_LOG_V - 1; k >= 0; k--)
        if (s >> k & 1) {
            imax = max(imax, dp_max[k][v]);
            res = max(res, dp_down[k][v]);
            res = max(res, pre_max - dp_min[k][v]);
            pre_max = max(pre_max, dp_max[k][v]);
            v = parent[k][v];
        }
    return res;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &V);
    for (int i = 0; i < V; i++) scanf("%d", A + i);
    for (int i = 0, u, v; i < V - 1; i++) {
        scanf("%d%d", &u, &v);
        --u, --v;
        G[u].push_back(v); G[v].push_back(u);
    }
    init(V);
    scanf("%d", &Q);
    for (int i = 0, u, v; i < Q; i++) {
        scanf("%d%d", &u, &v);
        --u, --v;
        int p = lca(u, v);
        // cout << p << " " << u << "<->" << v << endl;
        int imax, imin;
        int iup = up(u, depth[u] - depth[p], imin);
        int idown = down(v, depth[v] - depth[p], imax);
        // cout << imin << " " << imax << endl;
        printf("%d\n", max(max(iup, idown), imax - imin));
    }
    return 0;
}