//#include <bits/stdc++.h>
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
const int MAX_V = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

struct edge {
    int from;
    int to, dis;
};
vector<edge> es, vs;
bool vis[MAX_V];
int V, E, dist[MAX_V], t;

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
    init(V);
    int res = 0;
    for (int i = 0; i < E; ++i) {
        edge e = es[i];
        if (!same(e.from, e.to)) {
            unite(e.from, e.to);
            res += e.dis;
            vs.push_back(e);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		es.clear();
		vs.clear();
		scanf("%d%d", &V, &E);
		for (int i = 0, x, y, w; i < E; ++i) {
			scanf("%d%d%d", &x, &y, &w);
			--x; --y;
			es.push_back(edge{x, y, w});
		}
		int ans = kruskal();
		// cout << ans << endl;
		bool flag = false;
		for (int i = 0; i < vs.size() && !flag; ++i) {
			init(V);
			int res = 0, cnt = 0;
			for (int j = 0; j < E; ++j) {
			    edge e = es[j];
			    if (e.from == vs[i].from && e.to == vs[i].to) continue;
			    if (!same(e.from, e.to)) {
			        unite(e.from, e.to);
			        res += e.dis;
			        ++cnt;
			    }
			}
			if (res == ans && cnt == V - 1) flag = true;
		}
		if (flag)
			printf("Not Unique!\n");
		else printf("%d\n", ans);
	}
	return 0;
}