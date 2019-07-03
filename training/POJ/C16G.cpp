// written at 10:06 on 12 May 2017
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

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 1e6 + 10;

struct edge {
    int to, dis, next;
};
int n, G[MAX_N], En;
edge E[MAX_N * 10];

int dist[MAX_N * 10], ans[MAX_N], Vn;
edge V[MAX_N * 10];

void init() {
    En = 0;
    memset(G, -1, sizeof G);
    Vn = 0;
    memset(dist, -1, sizeof dist);

    for (int i = 1; i <= n; i++)
        ans[i] = INT_MAX / 3;
}

void addEdge(int v, int u, int w) {
    edge e = {u, w, G[v]};
    E[En] = e;
    G[v] = En++;
}

void addDist(int dis, int v) {
    edge e = {v, 0, dist[dis]};
    V[Vn] = e;
    dist[dis] = Vn++;
}

void printEdge() {
    for (int i = 0; i <= n; i++)
    {
        cout << i << "-----" << endl;
        for (int j = dist[i]; ~j; j = V[j].next) {
            cout << i << "->" << V[j].to << " " << V[j].dis << endl;
        }
    }
}

void buildGraph(int N, int Seed) {
    int nextRand = Seed;
    // initialize random number generator
    for (int x = 1; x <= N; x++) {
        // generate edges from Node x
        int w = x % 10 + 1;            // the weight of edges
        int d = 10 - w;                // the number of edges
        for (int i = 1; i <= d; i++) {
            addEdge(x, nextRand % N + 1, w);
            // add a new edge into G
            nextRand = nextRand * 233 % N;
        }
        addEdge(x, x % N + 1, w);
    }
}

int dijiskra(int s) {
    ans[s] = 0;
    addDist(0, s);
    for (int dis = 0; dis <= 10 * n; dis++) {
        for (int vit = dist[dis]; ~vit; vit = V[vit].next) {
            int v = V[vit].to;
            if (v == n) return dis;
            for (int j = G[v]; ~j; j = E[j].next) {
                int u = E[j].to, w = E[j].dis;
                if (ans[u] > ans[v] + w) {
                    ans[u] = ans[v] + w;
                    addDist(ans[u], u);
                }
            }
        }
    }
    return INT_MAX;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int seed;
        scanf("%d%d", &n, &seed);
        init();
        buildGraph(n, seed);
        printf("%d\n", dijiskra(1));
    }
    return 0;
}
