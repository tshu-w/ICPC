// written at 16:12 on 19 Jan 2017 
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
const int MAX_V = 500 + 10;

int V, G, B, E, t; 
vector<int> Graph[MAX_V];
int match[MAX_V];
bool used[MAX_V], mp[MAX_V][MAX_V];

void add_edge(int v, int u) {
	Graph[u].push_back(v); Graph[v].push_back(u);
}
bool dfs(int v) {
	used[v] = true;
	rep(i, 0, Graph[v].size()) {
		int u = Graph[v][i], w = match[u];
		if (w < 0 || (!used[w] && dfs(w))) {
			match[v] = u; match[u] = v;
			return true;
		}
	}
	return false;
}
int bipartite_match() {
	int res = 0;
	memset(match, -1, sizeof match);
	rep(v, 0, V) if (match[v] < 0) {
		memset(used, false, sizeof used);
		if (dfs(v)) ++res;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	while (scanf("%d%d%d", &G, &B, &E) && G + B + E) {
		V = G + B;
		int g, b;
		memset(mp, 0, sizeof mp);
		rep(i, 0, E) {
			scanf("%d%d", &g, &b); --g, --b;
			mp[g][b + G] = mp[b + G][g] = true;
		}
		rep(i, 0, V) Graph[i].clear();
		rep(i, 0, G) rep(j, G, V) if (!mp[i][j]) add_edge(i, j);
		printf("Case %d: %d\n", ++t, V - bipartite_match());
	}
	return 0;
}