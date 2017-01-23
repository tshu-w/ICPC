// written at 10:14 on 23 Jan 2017 
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
const int INF = INT_MAX / 3;
const ll LLINF = LLONG_MAX;
const int MAX_V = 1e4 + 10;

struct edge{int to, cap, cost, rev;};
vector<edge> G[MAX_V];
int V, N, K, A[MAX_V][MAX_V];
int prevv[MAX_V], preve[MAX_V], h[MAX_V], dist[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap, int cost) {
	G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
	G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
}
void spfa(int s) {
	queue<int> que;
	fill(dist, dist + V, INF);
	memset(used, false, sizeof used);
	dist[s] = 0; que.push(s); used[s] = true;
	while (!que.empty()) {
		int v = que.front(); que.pop();
		used[v] = false;
		rep(i, 0, G[v].size()) {
			edge &e = G[v][i];
			if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
				dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
				prevv[e.to] = v; preve[e.to] = i;
				if (!used[e.to]) {
					que.push(e.to); used[e.to] = true;
				}
			}
		}
	}
}
int min_cost_flow(int s, int t, int f) {
	int res = 0;
	memset(h, 0, sizeof h);
	while (f > 0) {
		spfa(s);
		if (dist[t] == INF) return -1;
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
	scanf("%d%d", &N, &K);
	int s = 0, t = 2 * N * N - 1;
	V = t + 1;
	rep(i, 0, N) rep(j, 0, N) scanf("%d", &A[i][j]);
	rep(i, 0, N) rep(j, 0, N) {
		if (i) add_edge((i - 1) * N + j + N * N, i * N + j, K, 0);
		if (j) add_edge(i * N + j - 1 + N * N, i * N + j, K, 0);
		add_edge(i * N + j, i * N + j + N * N, 1, -A[i][j]);
		add_edge(i * N + j, i * N + j + N * N, K - 1, 0);
	}
	printf("%d\n", -min_cost_flow(s, t, K));
	return 0;
}