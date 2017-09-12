// written at 14:03 on 3 Mar 2017
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
const int MAX_Q = 1e5 + 10;
struct edge{
    int id, to, cost;
    edge(int _id = 0, int _to = 0, int _cost = 0) : id(_id), to(_to), cost(_cost) {}
};

int n, q, s, A[MAX_V], B[MAX_V], W[MAX_V], type[MAX_Q], X[MAX_Q], T[MAX_Q];

vector<edge> G[MAX_V];
int root, id[MAX_V], vs[3 * MAX_V], depth[3 * MAX_V]; // 2 * MAX_V Wa 了，不知道为什么
int es[2 * MAX_V - 1];

int bit_n, bit[2 * MAX_V - 1];
void add(int i, int x) {
    // cout << i << " add " << x << endl;
    while (i <= bit_n) {
        bit[i] += x;
        i += i & -i;
    }
}
int sum(int i) {
    int res = 0;
    while (i > 0) {
        res += bit[i];
        i -= i & -i;
    }
    return res;
}

int rmq_n, data[8 * MAX_V];
int rmq_init(int k, int l, int r) {
    if (l + 1 == r) return data[k] = l;
    int ml = rmq_init(2 * k + 1, l, (l + r) / 2);
    int mr = rmq_init(2 * k + 2, (l + r) / 2, r);
    return data[k] = depth[ml] <= depth[mr]? ml : mr;
}
void rmq_init(int _n) {
    rmq_n = 1;
    while (rmq_n < _n) rmq_n <<= 1;
    // cout << rmq_n << endl;
    for (int i = _n; i <= rmq_n; i++)
        depth[i] = INF;
    rmq_init(0, 0, rmq_n);
}
int query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l) return rmq_n;
    if (a <= l && r <= b) return data[k];
    int ml = query(a, b, 2 * k + 1, l, (l + r) / 2);
    int mr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return depth[ml] <= depth[mr] ? ml : mr;
}

void dfs(int v, int p, int d, int &k) {
    id[v] = k;
    vs[k] = v;
    depth[k++] = d;
    for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.to != p) {
            add(k, e.cost);
            es[e.id * 2] = k;
            dfs(e.to, v, d + 1, k);
            vs[k] = v;
            depth[k++] = d;
            add(k, -e.cost);
            es[e.id * 2 + 1] = k;
        }
    }
}

void init(int V) {
    bit_n = 2 * V - 1;
    int k = 0;
    dfs(root, -1, 0, k);
    // for (int i  = 0; i < V; i++)
    //     cout << id[i] << " "; cout << endl;
    // for (int i = 0; i < 2 * V - 1; i++)
    //     cout << vs[i] << " "; cout << endl;
    // for (int i = 0; i < 2 * V - 1; i++)
    //     cout << depth[i] << " "; cout << endl;
    rmq_init(2 * V - 1);
    // for (int i = 0; i < 2 * rmq_n - 1; i++)
        // cout << data[i] << " "; cout << endl;
}
int lca(int v, int u) {
    return vs[query(min(id[v], id[u]), max(id[u], id[v]) + 1, 0, 0, rmq_n)];
}

void solve() {
    root = 0;
    for (int i = 0; i < n - 1; i++) {
        edge e1(i, B[i] - 1, W[i]), e2(i, A[i] - 1, W[i]);
        G[A[i] - 1].push_back(e1),
        G[B[i] - 1].push_back(e2);
    }
    init(n);

    int v = s - 1;
    for (int i = 0; i < q; i++) {
        scanf("%d%d", type + i, X + i);
        if (type[i]) scanf("%d", T + i);
        if (type[i] == 0) {
            int u = X[i] - 1;
            int p = lca(u, v);
            printf("%d\n", sum(id[u]) + sum(id[v]) - 2 * sum(id[p]));
            v = u;
        } else {
            int k = X[i] - 1;
            add(es[k * 2], T[i] - W[k]);
            add(es[k * 2 + 1], W[k] - T[i]);
            W[k] = T[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &q, &s);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d%d", A + i, B + i, W + i);
    }
    solve();
    return 0;
}
