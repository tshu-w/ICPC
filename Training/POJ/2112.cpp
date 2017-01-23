// written at 11:15 on 19 Jan 2017 
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
const int MAX_V = 1000 + 10;

struct edge {
	int to, cap, rev;
};
std::vector<edge> G[MAX_V];
bool flag[MAX_V];
int level[MAX_V], iter[MAX_V];
int V, E, K, C, M, mp[MAX_V][MAX_V];

void floyd() {
	rep(i, 1, V) rep(j, 1, V) if (!mp[i][j]) mp[i][j] = INF / 3;
	rep(k, 1, V) rep(i, 1, V) rep(j, 1, V)
		mp[i][j] = min(mp[i][k] + mp[k][j], mp[i][j]);
}

void add_edge(int from, int to, int cap) {
	G[from].push_back((edge){to, cap, (int)G[to].size()});
	G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
}
void bfs(int s) {
	memset(level, -1, sizeof level);
	queue<int> que;
	level[s] = 0; que.push(s);
	while (!que.empty()) {
		int v = que.front(); que.pop();
		rep(i, 0, G[v].size()) {
			edge &e = G[v][i];
			if (e.cap > 0 && level[e.to] < 0) {
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}
int dfs(int v, int t, int f) {
	if (v == t) return f;
	for (int &i = iter[v]; i < G[v].size(); ++i) {
		edge &e = G[v][i];
		if (e.cap > 0 && level[v] < level[e.to]) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int limit) {
	int s = 0, t = V;
	rep(v, 0, V + 1) G[v].clear();
	rep(i, 1, K + 1) rep(j, K + 1, V) 
		if (mp[i][j] <= limit) add_edge(i, j, 1);
	rep(v, 1, K + 1) add_edge(s, v, M);
	rep(v, K + 1, V) add_edge(v, t, 1);
	int flow = 0;
	for(;;) {
		bfs(s);
		if (level[t] < 0) return flow;
		memset(iter, 0, sizeof iter);
		int f;
		while ((f = dfs(s, t, INF)) > 0) 
			flow += f;
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &K, &C, &M);
	V = K + C + 1;
	rep(i, 1, V) rep(j, 1, V) scanf("%d", &mp[i][j]);
	floyd();
	int lb = 0, ub = INF / 3;
	while (lb + 1 < ub) {
		int mid = (lb + ub) / 2;
		if (max_flow(mid) < C) lb = mid;
		else ub = mid;
	}
	printf("%d\n", ub);
	return 0;
}