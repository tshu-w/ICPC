// written at 09:57 on 08 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
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

int t, n, G[30][30], cnt[2][30];
bool vis[30];
char s[1024];

void dfs(int u) {
    vis[u] = false;
    for (int v = 0; v < 26; v++)
        if (vis[v] && G[u][v]--)
            dfs(v);
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(G, 0, sizeof G);
        memset(cnt, 0, sizeof cnt);
        memset(vis, false, sizeof vis);
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            G[s[0] - 'a'][s[strlen(s) - 1] - 'a']++;
            vis[s[0] - 'a'] = vis[s[strlen(s) - 1] - 'a'] = true;
            cnt[0][s[0] - 'a']++; cnt[1][s[strlen(s) - 1] - 'a']++;
        }
        int st, ed; st = ed = -1;
        bool flag = true;
        for (int i = 0; i < 26; i++)
            if (cnt[0][i] != cnt[1][i]) {
                if (cnt[0][i] == cnt[1][i] + 1 && st == -1) st = i;
                else if (cnt[0][i] + 1 == cnt[1][i] && ed == -1) ed = i;
                else flag = false;
            }
        dfs(max(st, 0));
        for (int i = 0; i < 26; i++)
            if (vis[i]) {
                flag = false; break;
            }
        puts(flag ? "Ordering is possible." : "The door cannot be opened.");
    }
    return 0;
}
