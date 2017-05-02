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
const int MAX_V = 1e5 + 10;
const ull B = 100000007;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, du[MAX_V];
ull p[MAX_V];
vector<int> G[MAX_V];
queue<int> que;
map<ull, int> m;

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i = 0, u, v; i < N - 1; ++i) {
        scanf("%d%d", &u, &v);
        G[v].push_back(u);
        ++du[u];
    }
    for (int i = 1; i <= N; ++i)
        if (du[i] == 0)
            que.push(i);
    fill(p + 1, p + N + 1, 1);
    while (que.size()) {
        int v = que.front(); que.pop();
        ++m[p[v]];
        for (int i = 0; i < G[v].size(); ++i) {
            int u = G[v][i];
            p[u] += p[v] * B;
            --du[u];
            if (du[u] == 0) {
                que.push(u);
            }
        }
    }
    ull ans = 0; 
    for (map<ull, int>::iterator it = m.begin(); it != m.end(); ++it) {
        ans += ((ll)it->second * (it->second - 1)) / 2;
    }
    printf("%llu\n", ans);
    return 0;
}