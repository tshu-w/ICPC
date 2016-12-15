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
const int MAX_V = 2000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

struct edge {
    int to, cap, rev, dis;
};
vector<edge> G[MAX_V], G2[MAX_V];
int level[MAX_V], iter[MAX_V];
bool vis[MAX_V];
int V, E, dist[MAX_V];


void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, static_cast<int>(G[to].size()), 1});
    G[to].push_back((edge){from, 0, static_cast<int>(G[from].size() - 1), 1});
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (int i = 0; i < G[v].size(); ++i) {
            edge &e = G[v][i];
            // cout << v << "->" << e.to << " : " << e.cap << endl;
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

int max_flow(int s, int t) {
    int flow = 0;
    for (;;) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof iter);
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}


void add_edge2(int from, int to, int cap) {
    G2[from].push_back((edge){to, cap, static_cast<int>(G2[to].size()), 1});
    G2[to].push_back((edge){from, cap, static_cast<int>(G2[from].size() - 1), 1});
}

void spfa(int s) {
    queue<int> que;
    fill(dist, dist + V, INF);
    memset(vis, false, sizeof vis);
    dist[s] = 0; que.push(s); vis[s] = true;
    while (!que.empty()) {
        int v = que.front(); que.pop();
        vis[v] = false;
        for (int i = 0; i < G2[v].size(); ++i) {
            int u = G2[v][i].to;
            if (dist[u] > dist[v] + G2[v][i].dis) {
                dist[u] = dist[v] + G2[v][i].dis;
                if (!vis[u]) {
                    que.push(u);
                    vis[u] = true;
                }
            }
        }
    }
}

void rebuild(int s) {
    queue<int> que;
    memset(vis, false, sizeof vis);
    que.push(s); vis[s] = true;
    while (!que.empty()) {
    	int v = que.front(); que.pop();
    	// cout << v << endl;
    	for (int i = 0; i < G2[v].size(); ++i) {
    		int u = G2[v][i].to;
    		if (dist[v] - dist[u] == 1) {
    			add_edge(v, u, G2[v][i].cap);
    			// cout << v << "->" << u << endl;
				if (!vis[u]) {
	    			que.push(u);
	    			vis[u] = true;
	    		}
    		}
    	}
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &V, &E);
        for (int i = 0; i < MAX_V; ++i) {
        	G[i].clear(); G2[i].clear();
        }
        for (int i = 0, u, v, w; i < E; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            --u; --v;
            add_edge2(u, v, w);
        }
        spfa(V - 1);
        // for (int i = 0; i < V; ++i)
        	// cout << dist[i] << endl;
        rebuild(0);
        // cout << endl;
        printf("%d\n", max_flow(0, V - 1)); 
    }
    return 0;
}