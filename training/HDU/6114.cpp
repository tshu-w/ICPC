// written at 14:02 on 13 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
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

const int maxn = 1e3 + 10;
const ll mod = 1e9 + 7;

int n, m, dp[maxn][maxn], t;

template<typename T> T mod_pow(T x, T n, T mod) {
    T res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
    // return b ? mod_pow(a * a % mod, b >> 1, mod) * (b & 1 ? a : 1) % mod : 1;
}

ll fact[maxn + 10], iact[maxn + 10];
void init() {
    fact[0] = 1;
    for (int i = 1; i <= maxn; ++i)
        fact[i] = fact[i - 1] * i % mod;
    iact[maxn - 1] = mod_pow(fact[maxn - 1], mod - 2, mod);
    for (int i = maxn - 2; i >= 0; --i)
        iact[i] = iact[i + 1] * (i + 1) % mod;
}

ll C(int a, int b) {
    return fact[a] * iact[b] % mod * iact[a - b] % mod;
}

int main() {
    init();
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        if (n > m) swap(n, m);
        printf("%lld\n", C(m, n));
    }
    return 0;
}
