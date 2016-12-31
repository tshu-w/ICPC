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
const int MAX_V = 30000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

struct edge {
    int from;
    int to, dis;
};
vector<edge> G[MAX_V];
bool vis[MAX_V];
int V, E, dist[MAX_V], N, s;

void spfa(int s) {
    queue<int> que;
    fill(dist, dist + V, INF);
    fill(vis, vis + V, false);
    dist[s] = 0; que.push(s); vis[s] = true;
    while (!que.empty()) {
        int v = que.front(); que.pop();
        vis[v] = false;
        for (int i = 0; i < G[v].size(); ++i) {
            int u = G[v][i].to;
            if (dist[u] > dist[v] + G[v][i].dis) {
                dist[u] = dist[v] + G[v][i].dis;
                if (!vis[u]) {
                    que.push(u);
                    vis[u] = true;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	V = 0; s = INF;
	for (int i = 0, a, b; i < N; ++i) {
		scanf("%d%d", &a, &b);
		G[b + 1].push_back(edge{b + 1, a, -2});
		V = max(V, b + 1);
        s = min(s, a);
	}
    ++V;
	for (int i = 0; i + 1 < V; ++i) {
		G[i].push_back(edge{i, i + 1, 1});
        G[i + 1].push_back(edge{i + 1, i, 0});
	}
	spfa(V - 1);
	printf("%d\n", dist[V - 1] - dist[s]);
	return 0;
}