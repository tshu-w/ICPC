// written at 17:12 on 25 Mar 2017 
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
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
const int MAX_N = 55;
const ll MOD = 1e9 + 7;


ll X[MAX_N], dp[MAX_N][MAX_N][MAX_N];
int u[MAX_N][MAX_N], v[MAX_N][MAX_N];

int par[MAX_N];
int rnk[MAX_N];
void init(int n) {
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        rnk[i] = 0;
    }
}
int find(int x) {
    return par[x] == x? x : par[x] = find(par[x]);
}
bool same(int x, int y) {
    return find(x) == find(y);
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

class TreeMovingDiv2
{
public:
    int count(int n, vector<int> roots, vector<int> a, vector<int> b, vector<int> c) {
        int m = roots.size();
        for (int i = 0; i < m; i++) {
            X[0] = c[i];
            for (int k = 1; k < n - 1; k++) 
                X[k] = (a[i] * X[k - 1] + b[i]) % MOD;
            for (int j = 0; j < n - 1; j++) {
                u[i][j] = (roots[i] + j + 1) % n;
                v[i][j] = (roots[i] + (X[j] % (j + 1))) % n;
            }
        }

        ll ans = 0;
        for (int i = 0; i < n - 1; i++) dp[0][i][i] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n - 1; j++) {
                init(n);
                for (int k = 0; k < n - 1; k++)
                    if (j != k) unite(u[i][k], v[i][k]);
                for (int k = 0; k < n - 1; k++) {
                    if (same(u[i - 1][k], v[i - 1][k])) continue;
                    for (int c = 0; c < n - 1; c++)
                        (dp[i][j][c] += dp[i - 1][k][c]) %= MOD;
                }
            }
        }
        for (int j = 0; j < n - 1; j++) {
            init(n);
            for (int k = 0; k < n - 1; k++)
                if (j != k) unite(u[0][k], v[0][k]);
            for (int k = 0; k < n - 1; k++) {
                if (same(u[m - 1][k], v[m - 1][k])) continue;
                (ans += dp[m - 1][k][j]) %= MOD;
            }
        }
        return (int)ans;
    } 
};

int main() {
    
    return 0;
}