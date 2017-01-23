// written at 10:39 on 22 Jan 2017 
// no really understand 消圈
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
const int MAX_V = 2e2 + 10;
const int MAX_N = 1e2 + 10;

// struct edge{int to, cap, cost, rev;};
// vector<edge> G[MAX_V];
// int V;
// int prevv[MAX_V], preve[MAX_V], h[MAX_V], dist[MAX_V];

int N, M;
int X[MAX_N], Y[MAX_N], B[MAX_N];
int P[MAX_N], Q[MAX_N], C[MAX_N];
int E[MAX_N][MAX_N];

int g[MAX_V][MAX_V];
int pre[MAX_V][MAX_V];
bool used[MAX_V];

// void add_edge(int from, int to, int cap, int cost) {
// 	G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
// 	G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
// }
// int min_cost_flow(int s, int t, int f) {
// 	int res = 0;
// 	fill(h, h + V, 0);
// 	while (f > 0) {
// 		priority_queue<Pii, vector<Pii>, greater<Pii> > que;
// 		fill(dist, dist + V, INF / 3);
// 		dist[s] = 0; que.push(Pii(0, s));
// 		while (!que.empty()) {
// 			Pii p = que.top(); que.pop();
// 			int v = p.second;
// 			if (dist[v] < p.first) continue;
// 			rep(i, 0, G[v].size()) {
// 				edge &e = G[v][i];
// 				if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
// 					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
// 					prevv[e.to] = v;
// 					preve[e.to] = i;
// 					que.push(Pii(dist[e.to], e.to));
// 				}
// 			}
// 		}
// 		if (dist[t] == INF / 3) return -1;
// 		rep(v, 0, V) h[v] += dist[v];
// 		int d = f;
// 		for (int v = t; v != s; v = prevv[v]) {
// 			d = min(d, G[prevv[v]][preve[v]].cap);
// 		}
// 		f -= d;
// 		res += d * h[t];
// 		for (int v = t; v != s; v = prevv[v]) {
// 			edge &e = G[prevv[v]][preve[v]];
// 			e.cap -= d;
// 			G[v][e.rev].cap += d;
// 		}
// 	}
// 	return res;
// }

void solve() {
	int V = N + M + 1;
	rep(i, 0, V) rep(j, 0, V) g[i][j] = INF / 3;
	rep(j, 0, M) {
		int sum = 0;
		rep(i, 0, N) {
			int c = abs(X[i] - P[j]) + abs(Y[i] - Q[j]) + 1;
			g[i][N + j] = c;
			if (E[i][j] > 0) g[N + j][i] = -c;
			sum += E[i][j];
		}
		if (sum > 0)
			g[N + M][N + j] = 0;
		if (sum < C[j])
			g[N + j][N + M] = 0;
	}	
	rep(i, 0, V) rep(j, 0, V) pre[i][j] = i;
	rep(k, 0, V) rep(i, 0, V) rep(j, 0, V) {
		if (g[i][j] > g[i][k] + g[k][j]) {
			g[i][j] = g[i][k] + g[k][j];
			pre[i][j] = pre[k][j];
			if (i == j && g[i][i] < 0) {
				fill(used, used + V, false);
				for (int v = i; !used[v]; v = pre[i][v]) {
					used[v] = true;
					if (v != N + M && pre[i][v] != N + M) {
						if (v >= N)
							E[pre[i][v]][v - N]++;
						else E[v][pre[i][v] - N]--;
					}
				}
				puts("SUBOPTIMAL");
				rep(i, 0, N) rep(j, 0, M)
					printf("%d%c", E[i][j], j + 1 == M? '\n' : ' ');
				return;
			}
		}
	}
	puts("OPTIMAL");
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &M);
	rep(i, 0, N) scanf("%d%d%d", X + i, Y + i, B + i);
	rep(i, 0, M) scanf("%d%d%d", P + i, Q + i, C + i);
	rep(i, 0, N) rep(j, 0, M) scanf("%d", &E[i][j]);
	// 0 ~ N - 1 building;
	// N ~ N + M - 1 shelters;
	solve();
	// int s = N + M, t = s + 1;
	// V = t + 1;
	// int F = 0, cost = 0;
	// rep(i, 0, N) rep(j, 0, M) {
	// 	int c = abs(X[i] - P[j]) + abs(Y[i] - Q[j]) + 1;
	// 	add_edge(i, j + N, INF, c);
	// 	cost += E[i][j] * c;
	// }
	// rep(i, 0, N) add_edge(s, i, B[i], 0), F += B[i];
	// rep(j, 0, M) add_edge(j + N, t, C[j], 0);
	// if (min_cost_flow(s, t, F) < cost) {
	// 	puts("SUBOPTIMAL");
	// 	rep(j, N, N + M) rep(i, 0, G[j].size()) {
	// 		edge &e = G[j][i];
	// 		if (0 <= e.to && e.to < N) {
	// 			E[e.to][j - N] = e.cap;
	// 		}
	// 	}
	// 	rep(i, 0, N) rep(j, 0, M)
	// 		printf("%d%c", E[i][j], j + 1 == M? '\n' : ' ');
	// } else 
	// 	puts("OPTIMAL");

	return 0;
}