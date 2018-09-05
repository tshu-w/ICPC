// written at 10:45 on 10 Aug 2018
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

const int maxn = 1400000;
const ll mod = 1e9 + 7;

ll t, n, c, k;

int prime[maxn];
bool isPrime[maxn + 1];
template<typename T> T pow(T x, T n) {
    return n ? pow(x * x % mod, n >> 1) * (n & 1 ? x : 1) % mod : 1;
}
template<typename T> T inv(T x) {
    return x == 1 ? 1 : (mod - (mod / x) * inv(mod % x) % mod) % mod;
}
int seive(int n) {
    int p = 0;
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; ++i)
        if (isPrime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) isPrime[j] = false;
        }
    return p;
}
ll fact[maxn + 10], iact[maxn + 10];
void init() {
    seive(maxn);
    fact[0] = 1;
    for (int i = 1; i < maxn; ++i) fact[i] = fact[i - 1] * i % mod;
    iact[maxn - 1] = pow(fact[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 0; --i) iact[i] = iact[i + 1] * (i + 1) % mod;
}
ll C(int n, int m) {
    return fact[n] * iact[n - m] % mod * iact[m] % mod;
}

int main() {
    init();
    for (scanf("%lld", &t); t > 0; t--) {
        scanf("%lld%lld%lld", &c, &n, &k);
        int p = prime[c - 1];
        ll ans = 0;
        for (int j = 1; j <= k; j++) {
            ll a = C(p + j, p - 1);
            if (a == 1) ans = (ans + n) % mod;
            else ans = (ans + a * (pow(a, n) - 1 + mod) % mod * inv(a - 1) % mod) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
