// written at 14:00 on 22 Feb 2018
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const ll mod = 1e9 + 7;
const int maxk = 5000 + 5;

ll n, k;
ll dp[maxk][maxk];

template<typename T> T mod_pow(T x, T n, T mod) {
    T res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll fill(int a, int b, int c) {
    if (dp[a][b] != -1) return dp[a][b];
    if (a == 0) return dp[a][b] = mod_pow(2ll, (ll)c, mod);
    ll res = 0;
    if (b) res += b * fill(a - 1, b, c) % mod;
    if (c) res += c * fill(a - 1, b + 1, c - 1) % mod;
    return dp[a][b] = res % mod;
}

int main() {
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    cout << fill(k, 0, n) << endl;
    return 0;
}
