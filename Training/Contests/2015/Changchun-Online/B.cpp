include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> Pii;

const int MAX_N = 1E4 + 5;
const int MAX_E = 1E5 + 5;

vector<int> g[MAX_N];
int t, p, m, a, b, d[MAX_N];
ll v[MAX_N];
bool flag[MAX_N];

int dfs(int u, ll &sum) {
    sum += v[u];
    int num = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int pnt = g[u][i];
        if (!flag[pnt]) {
            flag[pnt] = true;
            num += dfs(pnt, sum);
        }
    }
    return num;
}
int main() 
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &p, &m);

        fill(d, d + p + 1, 0);
        fill(flag, flag + p + 1, false);
        for (int i = 1; i < MAX_N; ++i)
            g[i].clear();

        for (int i = 1; i <= p; ++i) 
            scanf("%lld", &v[i]);

        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
            d[a]++;
            d[b]++;
        }
        queue<int> que;
        while(!que.empty()) que.pop();
        
        for (int i = 1; i <= p; ++i) {
            if (d[i] <= 1) {
                if (d[i] == 1) que.push(i);
                flag[i] = true;
            }
        }
        while (!que.empty()) {
            int u = que.front();que.pop();
            flag[u] = true;
            for (int i = 0; i < g[u].size(); ++i) if (!flag[g[u][i]]) {
                int pnt = g[u][i];
                if (--d[pnt] <= 1) {
                    if (d[pnt] == 1) que.push(pnt);
                    flag[pnt] = true;
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= p; ++i)
            if (!flag[i]) {
                ll sum = 0;
                flag[i] = true;
                if (dfs(i, sum) & 1) 
                    ans += sum;
            }
        printf("%lld\n", ans);
    }
    return 0;
}