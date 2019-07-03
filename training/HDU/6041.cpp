// written at 20:29 on 26 Jul 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
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

const int MAX_N = 1e3 + 10;

struct edge {
    int to, dis;
};
struct opt {
    unsigned w;
    int x, y;
    opt (unsigned _w, int _x, int _y) : w(_w), x(_x), y(_y) {}
    bool operator <(const opt& R) const {
        return w < R.w;
    }
};

vector<edge> G[MAX_N];
int g[MAX_N][MAX_N];
vector<unsigned> sum, res, vt;
bool flag[MAX_N], vis[MAX_N];
int n, m, stck[MAX_N], top, K;
unsigned tot;
priority_queue<opt> que;

void merge(vector<unsigned> &sum, vector<unsigned> &vt) {
    while (!que.empty()) que.pop();
    res.clear();
    for (int i = 0; i < (int)vt.size(); i++)
        que.push(opt(vt[i] + sum[0], i, 0));
    while ((int)res.size() < K && !que.empty()) {
        opt tmp = que.top(); que.pop();
        res.push_back(tmp.w);
        if (tmp.y + 1 < (int)sum.size())que.push(opt(vt[tmp.x] + sum[tmp.y + 1], tmp.x, tmp.y + 1));
    }
    sum = res;
}

void dfs(int v, int p) {
    flag[v] = vis[v] = true;
    stck[top++] = v;
    for (edge e : G[v]) {
        int u = e.to, uu = u;
        if (u == p) continue;
        if (!vis[u]) dfs(u, v);
        if (flag[u]) {
            vt.clear();
            for (int i = top - 1; i >= 0; --i) {
                vt.push_back(g[uu][stck[i]]);
                uu = stck[i];
                if (uu == u) break;
            }
            merge(sum, vt);
        }
    }
    top--;
    flag[v] = false;
}

int main() {
    int cs = 0;
    sum.reserve(100001);
    res.reserve(100001);
    while (~scanf("%d%d", &n, &m)) {
        sum.clear(); sum.push_back(0);
        for (int i = 0; i < n; i++) {
            G[i].clear();
            flag[i] = vis[i] = false;
        }
        tot = 0; top = 0;

        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);--a, --b;
            tot += c;
            G[a].push_back(edge{b, c});
            G[b].push_back(edge{a, c});
            g[a][b] = g[b][a] = c;
        }
        scanf("%d", &K);

        dfs(0, -1);

        unsigned ans = 0;
        for (int i = 0; i < (int)sum.size(); i++) {
            ans += (unsigned)(i + 1) * (tot - sum[i]);
        }
        printf("Case #%d: %u\n", ++cs, ans);
    }
    return 0;
}
