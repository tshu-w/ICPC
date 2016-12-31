// written at 11:36 on 27 Dec 2016 
#include <bits/stdc++.h>

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
const int MAX_V = 1e3 + 10;

struct edge {
	int to, cap, rev;	
};
vector<edge> G[MAX_V];
bool flag[MAX_V];
int V, M, level[MAX_V], iter[MAX_V];

void add_edge(int from, int to, int cap) {
	G[from].push_back((edge){to, cap, (int)G[to].size()});
	G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
}
int dfs(int v, int t, int f) {
	if (v == t) return f;
	flag[v] = true;
	rep(i, 0, G[v].size()) {
		edge &e = G[v][i];
		if (!flag[e.to] && e.cap > 0) {
			int d = min(f, dfs(e.to, t, e.cap));
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
	for(;;) {
		memset(flag, false, sizeof flag);
		int f = dfs(s, t, INF);
		if (!f) return flow;
		flow += f;
	}
}
// void bfs(int s) {
//     memset(level, -1, sizeof(level));
//     queue<int> que;
//     level[s] = 0;
//     que.push(s);
//     while (!que.empty()) {
//         int v = que.front(); que.pop();
//         for (int i = 0; i < G[v].size(); ++i) {
//             edge &e = G[v][i];
//             if (e.cap > 0 && level[e.to] < 0) {
//                 level[e.to] = level[v] + 1;
//                 que.push(e.to);
//             }
//         }
//     }
// }
// int dfs(int v, int t, int f) {
//     if (v == t) return f;
//     for (int &i = iter[v]; i < G[v].size(); ++i) {
//         edge &e = G[v][i];
//         if (e.cap > 0 && level[v] < level[e.to]) {
//             int d = dfs(e.to, t, min(f, e.cap));
//             if (d > 0) {
//                 e.cap -= d;
//                 G[e.to][e.rev].cap += d;
//                 return d;
//             }
//         }
//     }
//     return 0;
// }
// int max_flow(int s, int t) {
//     int flow = 0;
//     for (;;) {
//         bfs(s);
//         if (level[t] < 0) return flow;
//         memset(iter, 0, sizeof iter);
//         int f;
//         while ((f = dfs(s, t, INF)) > 0) {
//             flow += f;
//         }
//     }
// }

int main(int argc, char const *argv[])
{
    while (scanf("%d%d", &V, &M) && V + M) {
        rep(i, 0, M) {
            int u, v;
            scanf("%d%d", &u, &v);
            add_edge(u, v, 1);
        }
        rep(i, 0, V) add_edge(V, i, 3);
        rep(i, 0, V) add_edge(i, V + 1, 3); 
        V += 2;
        cout << max_flow(V - 2, V - 1) << endl;
    }
    // rep(i, 0, M) {
    //     int a, b;
    //     scanf("%d%d", &a, &b);
    //     if (a != 4 && b != 5)
    //         add_edge(a, b, 1);
    //     else add_edge(a, b, 3);
    // }	
    // cout << max_flow(4, 5) << endl;
	return 0;
}