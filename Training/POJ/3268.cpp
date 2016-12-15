#include <bits/stdc++.h>

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
	int from, to, cost;
};
vector<edge> G[MAX_V];
int dist[MAX_V], d[MAX_V][MAX_V];

int V, E, X;
void dijkstra(int s) {
    priority_queue<Pii, vector<Pii>, greater<Pii> > que;// fisrt 是最短距离，second 是顶点编号
    fill(dist, dist + V, INF);
    dist[s] = 0; que.push(Pii(0, s));
    while (!que.empty()) {
        Pii p = que.top(); que.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                que.push(Pii(dist[e.to], e.to));
            }
        }
    } 
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &V, &E, &X); --X;	
	for (int i = 0, v, u, x; i < E; ++i) {
		scanf("%d%d%d", &v, &u, &x);
		--v, --u;
		G[v].push_back(edge{v, u, x});
	}
	for (int i = 0; i < V; ++i) {
		dijkstra(i);
		for (int j = 0; j < V; ++j)
			d[i][j] = dist[j];
	}
	int ans = 0;
	for (int i = 0; i < V; ++i)
		ans = max(ans, d[i][X] + d[X][i]);
	printf("%d\n", ans);
	return 0;
}