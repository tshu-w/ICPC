// written at 11:02 on 12 Sep 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename "12118"
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 1e3 + 10;

int V, E, T, du[maxn], cnt[maxn], bk;
vector<int> G[maxn];
int block[maxn];

void dfs(int v, int bk) {
    block[v] = bk;
    for (int i = 0; i < (int)G[v].size(); i++)
        if (!block[G[v][i]]) dfs(G[v][i], bk);
}

int main() {
    while (scanf("%d%d%d", &V, &E, &T) && V) {
        for (int i = 0; i < V; i++) G[i].clear();
        memset(block, -1, sizeof block);
        memset(du, 0, sizeof du);
        memset(cnt, 0, sizeof cnt);
        bk = 0;

        for (int i = 0, a, b; i < E; i++) {
            scanf("%d%d", &a, &b); --a; --b;
            block[a] = block[b] = 0;
            G[a].push_back(b); G[b].push_back(a);
            du[a]++; du[b]++;
        }
        for (int i = 0; i < V; i++)
            if (!block[i]) {
                dfs(i, ++bk);
            }
        for (int i = 0; i < V; i++)
            if (du[i] & 1 && block[i] > 0) cnt[block[i]]++;
        E += max(bk - 1, 0);
        for (int i = 1; i <= bk; i++) E += max(0, cnt[i] / 2 - 1);
        static int cs = 0;
        printf("Case %d: %d\n", ++cs, E * T);
    }
    return 0;
}
