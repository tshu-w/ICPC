// written at 11:19 on 4 Mar 2017 
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
const int MAX_K = 20;
struct edge { int to, cost; };

vector<edge> G[MAX_V];
int V, E, root, vs[MAX_V * 2], depth[MAX_V * 2], id[MAX_V], dist[MAX_V * 2];

int ST[2 * MAX_V][MAX_K];
void rmq_init(int* A, int N) {
    for (int i = 0; i < N; i++) 
        ST[i][0] = i;
    int k = 31 - __builtin_clz(N);
    for (int j = 1; j <= k; j++) 
        for (int i = 0; i <= N - (1 << j); ++i)
            if (A[ST[i][j - 1]] <= A[ST[i + (1 << (j - 1))][j - 1]])
                ST[i][j] = ST[i][j - 1];
            else ST[i][j] = ST[i + (1 << (j - 1))][j - 1];
}
int query(int l, int r) {
    if (l >= r) return -1;
    int k = 31 - __builtin_clz(r - l);
    return (depth[ST[l][k]] <= depth[ST[r - (1 << k)][k]]) ? ST[l][k] : ST[r - (1 << k)][k];
}

void dfs(int v, int p, int d, int &k) {
    id[v] = k;
    vs[k] = v;
    depth[k++] = d;
    for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.to != p) {
            dist[e.to] = dist[v] + e.cost;
            dfs(e.to, v, d + 1, k);
            vs[k] = v;
            depth[k++] = d;
        }
    }
}
void init() {
    root = 0;
    int k = 0;
    memset(dist, 0, sizeof dist);
    dfs(root, -1, 0, k);
    // for (int i = 0; i < V; i++)
    //     cout << id[i] << " "; cout << endl;
    // for (int i = 0; i < 2 * V - 1; i++)
    //     cout << vs[i] << " "; cout << endl;
    // for (int i = 0; i < 2 * V - 1; i++)
    //     cout << depth[i] << " "; cout << endl;
    // for (int i = 0; i < V; i++)
    //     cout << dist[i] << " "; cout << endl;
    rmq_init(depth, 2 * V - 1);
}
int lca(int v, int u) {
    return vs[query(min(id[v], id[u]), max(id[v], id[u]) + 1)];
}

void solve() {
    init();
    int K;
    scanf("%d", &K);
    for (int i = 0, u, v; i < K; i++) {
        scanf("%d%d", &u, &v);
        --u, --v;
        int p = lca(u, v);
        // cout << p << " " << u << "<->" << v << endl;
        printf("%d\n", dist[v] + dist[u] - 2 * dist[p]);
    }
}

int main(int argc, char const *argv[])
{
    while (~scanf("%d%d", &V, &E)) {
        for (int i = 0; i < V; i++) G[i].clear();
        int u, v, w; char c;
        for (int i = 0; i < V - 1; i++) {
            scanf("%d%d%d %c", &u, &v, &w, &c);
            --u, --v;
            G[u].push_back(edge{v, w});
            G[v].push_back(edge{u, w});
            // cout << u << "->" << v << " " << w << endl;
        }
        solve();
    }
    return 0;
}