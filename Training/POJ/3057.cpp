// written at 15:35 on 20 Jan 2017 
// Wonderful problem
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
const ll LLINF = LLONG_MAX;
const int MAX_V = 1e4 + 10;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
const int MAX_W = 15;

int X, Y;
char field[MAX_W][MAX_W];

vector<int> dX, dY, pX, pY;
int dist[MAX_W][MAX_W][MAX_W][MAX_W];

vector<int> G[MAX_V];
bool used[MAX_V];
int match[MAX_V];
int V;

void add_edge(int v, int u) {
    G[v].push_back(u); G[u].push_back(v);
}
bool dfs(int v) {
    used[v] = true;
    rep(i, 0, G[v].size()) {
        int u = G[v][i], w = match[u];
        if (w < 0 || (!used[w] && dfs(w))) {
            match[v] = u; match[u] = v;
            return true;
        }
    }
    return false;
}
int bipatite_match() {
    int res = 0;
    memset(match, -1, sizeof match);
    rep(i, 0, V) if (match[i] < 0) {
        memset(used, false, sizeof used);
        if (dfs(i)) ++res;
    }
    return res;
}

void bfs(int x, int y, int d[MAX_W][MAX_W]) {
    queue<int> qx, qy;
    d[x][y] = 0;
    qx.push(x); qy.push(y);
    while (!qx.empty()) {
        x = qx.front(); qx.pop();
        y = qy.front(); qy.pop();
        rep(i, 0, 4) {
            int xx = x + dx[i], yy = y + dy[i];
            if (0 <= xx && xx < X && 0 <= yy && yy < Y && field[xx][yy] == '.' && d[xx][yy] < 0) {
                d[xx][yy] = d[x][y] + 1;
                qx.push(xx);
                qy.push(yy);
            } 
        }
    }
}

bool C(int t) {
    int d = dX.size(), p = pX.size();
    V = t * d + p;
    rep(v, 0, V) G[v].clear();
    rep(i, 0, d) rep(j, 0, p) if (dist[dX[i]][dY[i]][pX[j]][pY[j]] >= 0)
        rep(k, dist[dX[i]][dY[i]][pX[j]][pY[j]], t + 1)
            add_edge((k - 1) * d + i, t * d + j);
    return bipatite_match() == p;
}

void solve() {
    int n = X * Y;
    dX.clear(); dY.clear();
    pX.clear(); pY.clear();
    memset(dist, -1, sizeof dist);
    rep(x, 0, X) rep(y, 0, Y) 
        if (field[x][y] == 'D') {
            dX.push_back(x); dY.push_back(y);
            bfs(x, y, dist[x][y]);
        }
        else if (field[x][y] == '.') {
            pX.push_back(x); pY.push_back(y);
        }

    int d = dX.size(), p = pX.size();
    V = n * d + p;
    rep(v, 0, V) G[v].clear();
    rep(i, 0, d) rep(j, 0, p) if (dist[dX[i]][dY[i]][pX[j]][pY[j]] >= 0)
        rep(k, dist[dX[i]][dY[i]][pX[j]][pY[j]], n + 1)
            add_edge((k - 1) * d + i, n * d + j);
    if (p == 0) {
        printf("0\n"); return;
    }
    int num = 0;
    memset(match, -1, sizeof match);
    rep(v, 0, n * d) {
        memset(used, 0, sizeof used);
        if (dfs(v)) {
            if (++num == p) {
                printf("%d\n", v / d + 1);
                return;
            }
        }
    }
    puts("impossible");
    // int lb = -1, ub = n + 1;
    // while (lb + 1 < ub) {
    //     int mid = (lb + ub) / 2;
    //     if (C(mid)) ub = mid; else lb = mid;
    // }
    // if (ub > n) puts("impossible");
    // else printf("%d\n", ub); 
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &X, &Y);
        rep(i, 0, X)
            scanf("%s", field[i]);
        solve();
    }
    return 0;
}