// written at 16:21 on 22 Jan 2017 
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
const int MAX_V = 3e3 + 10;

struct edge { int to, cap, cost, rev; };
vector<edge> G[MAX_V];
int V, prevv[MAX_V], preve[MAX_V], h[MAX_V], dist[MAX_V];

int t, N, M, z;

void add_edge(int from, int to, int cap, int cost) {
	// cout << from << "->" << to << " " << cap << " " << cost << endl;
	G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
	G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
}
int min_cost_flow(int s, int t, int f) {
	int res = 0;
	memset(h, 0, sizeof h);
	while (f > 0) {
		priority_queue<Pii, vector<Pii>, greater<Pii> > que;
		fill(dist, dist + V, INF / 3);
		dist[s] = 0; que.push(Pii(0, s));
		while (!que.empty()) {
			Pii p = que.top(); que.pop();
			int v = p.second;
			if (dist[v] < p.first) continue;
			rep(i, 0, G[v].size()) {
				edge &e = G[v][i];
				if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
					prevv[e.to] = v;
					preve[e.to] = i;
					que.push(Pii(dist[e.to], e.to));
				}
			}
		}
		if (dist[t] == INF / 3) return -1;
		rep(v, 0, V) h[v] += dist[v];
		int d = f;
		for (int v = t; v != s; v = prevv[v])
			d = min(d, G[prevv[v]][preve[v]].cap);
		f -= d;
		res += h[t] * d;
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
	// 0 ~ N - 1 toy
	// N ~ 2N - 1 fact1
	// ...
	// MN ~ (M + 1)N - 1 factM
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &N, &M);
		int s = (M + 1) * N, t = s + 1;
		V = t + 1;
		rep(i, 0, V) G[i].clear();
		rep(i, 0, N) add_edge(s, i, 1, 0);
		rep(i, N, (M + 1) * N) add_edge(i, t, 1, 0);
		rep(i, 0, N) rep(j, 0, M) {
			scanf("%d", &z);
			rep(k, 0, N) add_edge(i, (j + 1) * N + k, 1, (k + 1) * z);
		}
		printf("%.6f\n", (double)min_cost_flow(s, t, N) / N);
	}
	return 0;
}