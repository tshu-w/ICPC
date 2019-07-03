// written at 16:23 on 23 Dec 2016
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <climits>

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
#define irep(i, j, k) for (int i = (j) - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

// const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 17;
const int MAX_S = 1 << MAX_N;

int t, n, m, M, dp[MAX_S][MAX_N], c[MAX_N][MAX_N];
bool flag[MAX_S][MAX_N];
string s[MAX_N], ans;

bool cmp1(string s1, string s2) {
    return s1.size() >= s2.size();
}
bool cmp(string s1, string s2) {
    return s1 + s2 < s2 + s1;
}

void distinc() {
    sort(s, s + n, cmp1);
    m = 1;
    rep(i, 1, n) {
        bool flag = true;
        rep(j, 0, m)
        if (s[j].find(s[i]) != string::npos) flag = false;
        if (flag)
            s[m++] = s[i];
    }
    sort(s, s + m, cmp);
    M = (1 << m) - 1;
}

int cnt(int a, int b) {
    if (a == b) return 0;
    int la = s[a].size(), lb = s[b].size();
    int len = min(la, lb);
    irep(k, len, 1)
    if (s[a].substr(la - k, k) == s[b].substr(0, k))
        return lb - k;
    return lb;
}

void DP() {
    rep(S, 0, 1 << m) rep(i, 0, m) dp[S][i] = INF;
    rep(i, 0, m) dp[1 << i][i] = s[i].size();
    rep(S, 0, 1 << m)
        rep(v, 0, m) if (dp[S][v] != INF)
            rep(u, 0, m) if (!(S >> u & 1))
                    dp[S | 1 << u][u] = min(dp[S | 1 << u][u], dp[S][v] + c[v][u]);
}
void judge(int imin) {
    memset(flag, false, sizeof flag);
    rep(i, 0, m) if (dp[M][i] == imin) flag[M][i] = true;
    irep(S, (1 << m), 1)
        rep(u, 0, m) if (flag[S][u])
            rep(v, 0, m)
                flag[S & ~(1 << u)][v] |= (dp[S][u] == dp[S & ~(1 << u)][v] + c[v][u]);
}

void dfs(int S, int v, int imin, string res = "") {
    if (S == M && dp[S][v] == imin)
        ans = min(res, ans);
    int it = -1;
    string tail = "z";
    rep(u, 0, m) if (!(S >> u & 1))
        if (dp[S | 1 << u][u] == dp[S][v] + c[v][u] && flag[S | 1 << u][u])
            if (s[u].substr(s[u].size() - c[v][u], c[v][u]) < tail) {
                tail = s[u].substr(s[u].size() - c[v][u], c[v][u]);
                it = u;
            }
    if (it != -1)
        dfs(S | 1 << it, it, imin, res + s[it].substr(s[it].size() - c[v][it], c[v][it]));
}

void solve(int tt) {
    distinc();
    rep(i, 0, m) rep(j, 0, m) c[i][j] = cnt(i, j);
    DP();
    printf("Scenario #%d:\n", tt);
    int imin = *min_element(dp[M], dp[M] + m);
    judge(imin);
    ans = "z";
    rep(i, 0, m) {
        dfs(1 << i, i, imin, s[i]);
        if (ans != "z") break;
    }
    cout << ans << endl << endl;
}

int main() {
    scanf("%d", &t);
    rep(tt, 0, t) {
        scanf("%d", &n);
        rep(i, 0, n) cin >> s[i];
        solve(tt + 1);
    }
    return 0;
}