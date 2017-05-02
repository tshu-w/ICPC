// written at 20:11 on 20 Mar 2017
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
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 2e5 + 10;

vector<int> G[MAX_N];
int count_subtree[MAX_N][5];
int total_subtree[MAX_N];
ll ans;
int n, k;

int subtract(int a, int b) {
    return ((a - b) % k + k) % k;
}
void dfs(int v, int p, int d) {
    count_subtree[v][d % k] = total_subtree[v] = 1;
    for (int u: G[v]) if (u != p) {
        dfs(u, v, d + 1);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                int reminder = subtract(i + j, 2 * d);
                int needs = subtract(k, reminder);
                ans += (ll)needs * count_subtree[v][i] * count_subtree[u][j];
            }
        }
        for (int i = 0; i < k; i++)
            count_subtree[v][i] += count_subtree[u][i];
        total_subtree[v] += total_subtree[u];
    }
    ans += (ll) total_subtree[v] * (n - total_subtree[v]);
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, -1, 0);
    cout << (ans / k) << endl;
    return 0;
}