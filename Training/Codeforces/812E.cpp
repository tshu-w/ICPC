// written at 15:13 on 02 Jun 2017
#include <bits/stdc++.h>

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

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 1e5 + 10;

int n, A[MAX_N], P[MAX_N], C[MAX_N], flag;
vector<int> G[MAX_N];
map<int, int> mp;

void dfs(int v) {
    if (G[v].size() == 0)
        flag = C[v];
    for (auto u: G[v]) {
        C[u] = !C[v];
        dfs(u);
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", A + i);
    for (int i = 1; i < n; i++) {
        scanf("%d", P + i);
        G[--P[i]].push_back(i);
    }
    C[0] = 0;
    dfs(0);
    int s = 0, cnt = 0;
    for (int i = 0; i < n; i++)
        if (C[i] == flag) {
            s ^= A[i];
            cnt++;
        } else mp[A[i]]++;
    ll ans = 0;
    if (s == 0) {
        ans = (ll)cnt * (cnt - 1) / 2 + (ll)(n - cnt) * (n - cnt - 1) / 2;
        for (int i = 0; i < n; i++) if (C[i] == flag){
                ans = ans + (ll)mp[A[i]];
            }
    } else {
        for (int i = 0; i < n; i++) if (C[i] == flag){
                ans = ans + (ll)mp[s ^ A[i]];
        }
    }
    cout << ans << endl;
    return 0;
}
