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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_V = 5000 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

struct edge
{
	int u, v, dis;	
};
vector<edge> G[MAX_V]; 
int N, R, dist[MAX_V], dist2[MAX_V];

void solve() {
	priority_queue<Pii, vector<Pii>, greater<Pii> > que;
	fill(dist, dist + N, INF);
	fill(dist2, dist2 + N, INF);
	dist[0] = 0;
	que.push(Pii(0, 0));

	while (!que.empty()) {
		Pii p = que.top(); que.pop();
		int u = p.second, d = p.first;
		if (dist2[u] < d) continue;
		for (int i = 0; i < G[u].size(); ++i) {
			edge e = G[u][i];
			int d2 = d + e.dis;
			if (d2 < dist[e.v]) {
				swap(d2, dist[e.v]);
				que.push(Pii(dist[e.v], e.v));
			}
			if (d2 < dist2[e.v] && d2 > dist[e.v]) {
				dist2[e.v] = d2;
				que.push(Pii(dist2[e.v], e.v));
			}
		}
	}
	printf("%d\n", dist2[N - 1]);
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &R);
	for (int i = 0; i < R; ++i) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		--a; --b;
		G[a].push_back(edge{a, b, d});
		G[b].push_back(edge{b, a, d});
	}
	solve();	
	return 0;
}