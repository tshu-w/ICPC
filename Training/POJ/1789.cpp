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
const int MAX_N = 2000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N;
char s[MAX_N][10];

struct edge {
    int from;
    int to, dis;
};
vector<edge> G[MAX_N];
bool vis[MAX_N];
int V, E, pre[MAX_N], dist[MAX_N];

int prime() {
    priority_queue<Pii, vector<Pii>, greater<Pii> > que;
    int res = 0;
    fill(dist, dist + N, INF);
    fill(vis, vis + N, false);
    dist[0] = 0;
    que.push(Pii(0, 0));
    while (!que.empty()) {
        Pii p = que.top(); que.pop();
        int v = p.second;
        if (vis[v] || dist[v] < p.first) continue;
        res += dist[v]; vis[v] = true;
        for (int i = 0; i < G[v].size(); ++i) {
            edge e = G[v][i];
            if (dist[e.to] > e.dis) {
                dist[e.to] = e.dis;
                que.push(Pii(dist[e.to], e.to));
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    while (~scanf("%d", &N) && N) {
        for (int i = 0; i < N; ++i) {
            G[i].clear();
            scanf("%s", s[i]);
        }
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j) {
                int res = 0;
                for (int k = 0; k < 7; ++k)
                    if (s[i][k] != s[j][k]) ++res;
                G[i].push_back(edge{i, j, res});
                G[j].push_back(edge{j, i, res});
            }
        int ans = prime();
        printf("The highest possible quality is 1/%d.\n", ans);
    }
    return 0;
}