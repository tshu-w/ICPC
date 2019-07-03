// written at 19:03 on 09 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename "test.in"
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

const int maxv = 26 * 2;

int n, c[maxv], a[4];
bool G[maxv][maxv];
char s[10];

int ID(char ch1, char ch2) {
    if (ch1 == '0' && ch2 == '0') return -1;
    return ch1 - 'A' + (ch2 == '+'? 26 : 0);
}

inline int trans(int u) {
    if (u >= 26) return u - 26;
    else return u + 26;
}

bool dfs(int u) {
    c[u] = -1;
    for (int v = 0; v < maxv; v++)
        if (G[u][v]) {
            if (c[trans(v)] < 0) return false;
            else if (!c[trans(v)] && !dfs(trans(v))) return false;
        }
    c[u] = 1;
    return true;
}

bool solve() {
    memset(c, 0, sizeof c);
    for (int u = 0; u < maxv; u++)
        if (!c[u])
            if (!dfs(u)) return false;
    return true;
}

int main() {
    while (~scanf("%d", &n)) {
        memset(G, false, sizeof G);
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            for (int j = 0; j < 4; j++)
                a[j] = ID(s[j * 2], s[j * 2 + 1]);
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    if (j != k && a[j] != -1 && a[k] != -1)
                        G[a[j]][a[k]] = G[a[k]][a[j]] = true;
        }
        puts(solve()? "bounded" : "unbounded");
    }
    return 0;
}
