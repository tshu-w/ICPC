// written at 09:38 on 09 Aug 2017
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

const int maxn = 2e2 + 10;

char buf[maxn][maxn];
int t, n;

void dfs(int r, int c) {
    printf("%c(", buf[r][c]);
    if (r + 1 < n && buf[r + 1][c] == '|') {
        int p = c;
        while (buf[r + 2][p - 1] == '-') p--;
        while (buf[r + 2][p] == '-' && buf[r + 3][p] != '\n') {
            if (!isspace(buf[r + 3][p])) dfs(r + 3, p);
            p++;
        }
    }
    printf(")");
}

void solve() {
    n = 0;
    while (fgets(buf[n], sizeof buf, stdin) && buf[n][0] != '#') n++;
    printf("(");
    if (n)
        for (int i = 0; i < (int)strlen(buf[0]); i++)
            if (buf[0][i] != ' ') {
                dfs(0, i);
                break;
            }
    printf(")\n");
}

int main() {
    fgets(buf[0], sizeof buf, stdin);
    sscanf(buf[0], "%d", &t);
    while (t--) solve();
    return 0;
}
