// written at 15:57 on 04 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";
};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 1e3 + 10;

char s[maxn];
bool flag;

struct Bitree {
    int tot;
    int lft[maxn], rgh[maxn], val[maxn];
    bool vis[maxn];
    void init() {
        lft[0] = rgh[0] = 0; vis[0] = false;
        tot = 1;;
    }
    int newNode() {
        lft[tot] = rgh[tot] = 0; vis[tot] = false;
        return tot++;
    }
    void addNode(int v, char *s) {
        int n = strlen(s), u = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                if (!lft[u]) lft[u] = newNode();
                u = lft[u];
            } else if (s[i] == 'R') {
                if (!rgh[u]) rgh[u] = newNode();
                u = rgh[u];
            }
        }
        if (vis[u]) flag = true;
        val[u] = v;
        vis[u] = true;
    }
    void bfs(vector<int> &ans) {
        queue<int> que;
        que.push(0);
        while (!que.empty()) {
            int u = que.front(); que.pop();
            if (!vis[u]) {
                flag = true; return ;
            }
            ans.push_back(val[u]);
            if (lft[u]) que.push(lft[u]);
            if (rgh[u]) que.push(rgh[u]);
        }
    }

}bt;

bool read() {
    bt.init();
    flag = false;
    while (true) {
        if (scanf("%s", s) != 1) return false;
        if (!strcmp(s, "()")) break;
        int v;
        sscanf(s + 1, "%d", &v);
        bt.addNode(v, strchr(s, ',') + 1);
    }
    return true;
}

int main() {
    while (read()) {
        vector<int> ans;
        bt.bfs(ans);
        if (flag) puts("not complete");
        else for (int i = 0; i < (int)ans.size(); i++)
                 printf("%d%c", ans[i], " \n"[i + 1 == (int)ans.size()]);
    }
    return 0;
}
