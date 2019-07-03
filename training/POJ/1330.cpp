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
const int MAX_V = 1e4 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

vector<int> G[MAX_V];
int root, n;

int parent[MAX_V], depth[MAX_V];
bool flag[MAX_V];

void dfs(int v, int p, int d) {
    parent[v] = p;
    depth[v] = d;
    for (int i = 0; i < G[v].size(); ++i)
        if (G[v][i] != p) dfs(G[v][i], v, d + 1);
}
int lca(int u, int v) {
    while (depth[u] > depth[v]) u = parent[u];
    while (depth[v] > depth[u]) v = parent[v];
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < MAX_V; ++i) G[i].clear();
        memset(flag, 0, sizeof flag);
        int u, v;
        scanf("%d", &n);
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &v, &u);
            G[v].push_back(u);
            flag[u] = true;
        }
        for (int i = 1; i <= n; ++i)
            if (!flag[i]) { root = i; break;}
        dfs(root, -1, 0);
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}