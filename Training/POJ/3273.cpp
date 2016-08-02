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

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;

const int MAX_V = 20005;
const int MAX_E = 50005;

struct edge {
    int u, v;
    int dis;
};
edge es[MAX_E];
int V, E;

int par[MAX_V];
int rnk[MAX_V];

bool cmp(const edge &e1, const edge &e2) {
    return e1.dis < e2.dis;
}

void init(int n) {
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        rnk[i] = 0;
    }
}
int find(int x) {
    return (par[x] == x)? x : par[x] = find(par[x]);
}
bool same(int a, int b) {
    return (find(a) == find(b));
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}
int kruskal() {
    init(V);
    sort(es, es + E, cmp);
    int res = 0;
    for (int i = 0; i < E; ++i) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.dis;
        }
    }
    return res;
}
int main(void) {
    int t, n, m, u, v, dis;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &E);
        V = n + m;
        for (int i = 0; i < E; ++i) {
            scanf("%d%d%d", &u, &v, &dis);
            es[i] = (edge){u, n + v, -dis};
        }
        printf("%d\n", 10000 * V + kruskal());
    }
    return 0;
}