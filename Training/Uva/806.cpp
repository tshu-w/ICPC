// written at 16:35 on 07 Sep 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename "806"
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

const int maxn = 100;

int n;
char s[maxn][maxn];
int sum[maxn][maxn];
ll pw[10];
vector<ll> ans;
vector<ll> v;

void init() {
    pw[0] = 1;
    for (int i = 1; i < 10; i++)
        pw[i] = pw[i - 1] * 5;
}

void dfs(int a, int b, int c, int d, ll num, int dep) {
    if (sum[c][d] - sum[c][b] - sum[a][d] + sum[a][b] == (c - a) * (d - b)) {
        ans.push_back(num);
        return ;
    }
    if (sum[c][d] - sum[c][b] - sum[a][d] + sum[a][b] == 0) return ;
    int m1 = (a + c) / 2, m2 = (b + d) / 2;
    dfs(a, b, m1, m2, num + pw[dep] * 1, dep + 1);
    dfs(a, m2, m1, d, num + pw[dep] * 2, dep + 1);
    dfs(m1, b, c, m2, num + pw[dep] * 3, dep + 1);
    dfs(m1, m2, c, d, num + pw[dep] * 4, dep + 1);
}

void g2s() {
    ans.clear();
    memset(sum, 0, sizeof sum);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (s[i][j] - '0');
    dfs(0, 0, n, n, 0, 0);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++)
        printf("%lld%c", ans[i], " \n"[i + 1 == (int)ans.size() || i % 12 == 11]);
    printf("Total number of black nodes = %d\n", (int)ans.size());
}

void dfs2(int a, int b, int c, int d, ll num) {
    int m1 = (a + c) / 2, m2 = (b + d) / 2, m = num % 5;
    if (m == 0)
        for (int i = a; i < c; i++)
            for (int j = b; j < d; j++)
                s[i][j] = '*';
    if (m == 1) dfs2(a, b, m1, m2, num / 5);
    if (m == 2) dfs2(a, m2, m1, d, num / 5);
    if (m == 3) dfs2(m1, b, c, m2, num / 5);
    if (m == 4) dfs2(m1, m2, c, d, num / 5);
}

void s2g() {
    int x;
    n = -n;
    v.clear();
    while (~scanf("%d", &x) && x != -1) {
        v.push_back(x);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            s[i][j] = '.';
    for (int i = 0; i < (int)v.size(); i++)
        dfs2(0, 0, n, n, v[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            putchar(s[i][j]);
        puts("");
    }
}

int main() {
    init();
    while (~scanf("%d", &n) && n) {
        static int cs = 0;
        if (cs) puts("");
        printf("Image %d\n", ++cs);
        if (n > 0) g2s(); else s2g();
    }
    return 0;
}
