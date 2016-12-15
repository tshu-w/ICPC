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
const int MAX_N = 13;
const int MOD = 100000000;
int N, M, dp[2][1 << MAX_N], flag[MAX_N];

void solve() {
    int *crt = dp[0], *nxt = dp[1];
    crt[0] = 1;
    rep(i, 0, N) {
        rep(S, 0, 1 << M) {
            nxt[S] = 0;
            if ((S & flag[i]) == S && !(S & (S << 1))) {
                int sup = ((1 << M) - 1) - S, sub = sup;
                do {
                    nxt[S] = (nxt[S] + crt[sub]) % MOD;
                    sub = (sub - 1) & sup;
                } while (sub != sup);
            };
        }
        swap(crt, nxt);
        // rep(S, 0, 1 << M) cout << crt[S] << " "; cout << endl;
    }
    int ans = 0;
    rep(S, 0, 1 << M) ans = (ans + crt[S]) % MOD;
    printf("%d\n", ans);
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &N, &M);
    rep(i, 0, N) rep(j, 0, M) {
        int a; 
        scanf("%d", &a);
        flag[i] = flag[i] * 2 + a;
    }
    solve();
    return 0;
}
/*
int N, M, dp[2][1 << MAX_N];
bool flag[MAX_N][MAX_N];

void solve() {
    int *crt = dp[0], *nxt = dp[1];
    crt[0] = 1;
    rep(i, 0, N)
        rep(j, 0, M) {
            rep(S, 0, 1 << M) nxt[S] = 0;
            rep(S, 0, 1 << M) {
                if (S >> j & 1) 
                    nxt[S & ~(1 << j)] = (nxt[S & ~(1 << j)] + crt[S]) % MOD;
                else {
                    nxt[S] = (nxt[S] + crt[S]) % MOD;
                    if (((j && !(S & (1 << (j - 1)))) || !j) && flag[i][j])
                        nxt[S | 1 << j] = (nxt[S | 1 << j] + crt[S]) % MOD;
                }
            }
            swap(crt, nxt);
            rep(S, 0, 1 << M) cout << crt[S] << " "; cout << endl;
        }
    int ans = 0;
    rep(S, 0, 1 << M) cout << crt[S] << " "; cout << endl;
    rep(S, 0, 1 << M) ans = (ans + crt[S]) % MOD;
    printf("%d\n", ans);
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &N, &M);
    rep(i, 0, N) rep(j, 0, M) {
        int a; 
        scanf("%d", &a);
        flag[i][j] = a;
    }
    solve();
    return 0;
}
*/
