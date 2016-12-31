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
const int MAX_V = 100 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

struct edge {
    int from;
    int to, dis;
};
vector<edge> es;
bool vis[MAX_V];
int V, E, dist[MAX_V], q;

int par[MAX_V];
int rnk[MAX_V];
void init(int n) {
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        rnk[i] = 0;
    }
}
int find(int x) {
    return par[x] == x? x : par[x] = find(par[x]);
}
bool same(int x, int y) {
    return find(x) == find(y);
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

bool cmp(const edge e1, const edge e2) {
    return e1.dis < e2.dis;
}
int kruskal() {
    sort(es.begin(), es.end(), cmp);
    int res = 0;
    for (int i = 0; i < E; ++i) {
        edge e = es[i];
        if (!same(e.from, e.to)) {
            unite(e.from, e.to);
            res += e.dis;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &V);
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j) {
			int a;
			scanf("%d", &a);
			if (i != j) es.push_back(edge{i, j, a});
		}
	init(V);
	scanf("%d", &q);
	for (int i = 0, u, v; i < q; ++i) {
		scanf("%d%d", &u, &v); --u; --v;
		unite(u, v);
	}
	E = es.size();
	int ans = kruskal();
	printf("%d\n", ans);
	return 0;
}