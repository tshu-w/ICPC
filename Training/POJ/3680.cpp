// written at 20:56 on 22 Jan 2017 
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
const int MAX_V = 2e3 + 10;

struct edge{ int to, cap, cost, rev; };
int V, t, K, N, A[MAX_V], B[MAX_V], W[MAX_V];
vector<edge> G[MAX_V];
int prevv[MAX_V], preve[MAX_V], h[MAX_V], dist[MAX_V];
bool vis[MAX_V];

void spfa(int s) {
    queue<int> que;
    fill(dist, dist + V, INF / 3);
    fill(vis, vis + V, false);
    dist[s] = 0; que.push(s); vis[s] = true;
    while (!que.empty()) {
        int v = que.front(); que.pop();
        vis[v] = false;
        for (int i = 0; i < G[v].size(); ++i) {
        	edge &e = G[v][i];
			if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
				dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
				prevv[e.to] = v; preve[e.to] = i;
				if (!vis[e.to]) {
					que.push(e.to);
					vis[e.to] = true;
				}
			}
        }
    }
}

void add_edge(int from, int to, int cap, int cost) {
	G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
	G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
}
int min_cost_flow(int s, int t, int f) {
	int res = 0;
	memset(h, 0, sizeof h);
	while (f > 0) {
		// fill(dist, dist + V, INF / 3);
		// priority_queue<Pii, vector<Pii>, greater<Pii> > que;
		// dist[s] = 0; que.push(Pii(0, s));
		// while (!que.empty()) {
		// 	Pii p = que.top(); que.pop();
		// 	int v = p.second;
		// 	rep(i, 0, G[v].size()) {
		// 		edge &e = G[v][i];
		// 		if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
		// 			dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
		// 			prevv[e.to] = v; preve[e.to] = i;
		// 			que.push(Pii(dist[e.to], e.to));
		// 		}
		// 	}
		// }
		spfa(s);
		if (dist[t] == INF / 3) return -1;
		rep(v, 0, V) h[v] += dist[v];
		int d = f;
		for (int v = t; v != s; v = prevv[v]) 
			d = min(d, G[prevv[v]][preve[v]].cap);
		f -= d;
		res += d * h[t];
		for (int v = t; v != s; v = prevv[v]) {
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		vector<int> x;
		scanf("%d%d", &N, &K);
		rep(i, 0, N) scanf("%d%d%d", A + i, B + i, W + i), x.push_back(A[i]), x.push_back(B[i]);
		sort(x.begin(), x.end());
		x.erase(unique(x.begin(), x.end()), x.end());
		int m = x.size();
		int s = m, t = s + 1; V = t + 1;
		int res = 0;
		rep(v, 0, V) G[v].clear();
		add_edge(s, 0, K, 0);
		add_edge(m - 1, t, K, 0);
		rep(i, 0, m - 1) add_edge(i, i + 1, INF / 3, 0);
		rep(i, 0, N) {
			int u = lower_bound(x.begin(), x.end(), A[i]) - x.begin();
			int v = lower_bound(x.begin(), x.end(), B[i]) - x.begin();
			add_edge(u, v, 1, -W[i]);
			// add_edge(s, v, 1, 0);
			// add_edge(u, t, 1, 0);
			// add_edge(v, u, 1, W[i]);
			// res -= W[i];
		}
		// res += min_cost_flow(s, t, K + N); // + N!!!
		res = min_cost_flow(s, t, K);
		printf("%d\n", -res);
	}	
	return 0;
}