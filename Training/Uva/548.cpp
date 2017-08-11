// written at 15:22 on 05 Aug 2017
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

const int maxn = 1e4 + 10;

int n, in_oder[maxn], post_order[maxn];
Pii ans;

struct Bitree {
    int tot, lft[maxn], rgh[maxn], val[maxn];
    void init() {
        tot = 0;
    }
    int newnode(int v) {
        lft[tot] = rgh[tot] = 0; val[tot] = v;
        return tot++;
    }
    int build(int l1, int r1, int l2, int r2) {
        if (l1 >= r1) return 0; if (l2 >= r2) return 0;
        int u = newnode(post_order[r2 - 1]), p;
        for (p = l1; p < r1; p++)
            if (in_oder[p] == post_order[r2 - 1]) break;
        lft[u] = build(l1, p, l2, l2 + p - l1);
        rgh[u] = build(p + 1, r1, l2 + p - l1, r2 - 1);
        return u;
    }
    void dfs(int u, int sum) {
        sum += val[u];
        if (!lft[u] && !rgh[u]) ans = min(Pii(sum, val[u]), ans);
        if (lft[u]) dfs(lft[u], sum);
        if (rgh[u]) dfs(rgh[u], sum);
    }
}bt;

bool read(int *A) {
    string line;
    if (!getline(cin, line)) return false;
    stringstream ss(line);
    n = 0;
    int x;
    while (ss >> x) A[n++] = x;
    return n > 0;
}

int main() {
    while (read(in_oder) && read(post_order)) {
        bt.init();
        bt.build(0, n, 0, n);
        ans = Pii(INT_MAX, INT_MAX);
        bt.dfs(0, 0);
        printf("%d\n", ans.second);
    }
    return 0;
}
