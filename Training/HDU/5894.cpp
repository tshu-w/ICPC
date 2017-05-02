#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif    
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;
const ll MOD = 1e9 + 7;

int t;
ll n, m, k;

template <typename T>
inline T sqr(T a) { return a * a;};

template<typename T> T mps(T l, T r, T k) { 
    return ((r - (r % k + k) % k) - (l + (k - l % k) % k)) / k + 1;
}
template<typename T> T gcd(T a, T b) {
    //return (b)? gcd(b, a  % b) : a;
    while (b) { T t = a % b; a = b; b = t; } return a;
}
template<typename T> T lcm(T a, T b) { 
    return a / gcd(a, b) * b;
}
// find (x, y) s.t. a x + b y = gcd(a, b) = d
template<typename T> T exgcd(T a, T b, T &x, T &y) { 
    T d = a; 
    if (b) { 
        d = exgcd(b, a % b, y, x); 
        y -= a / b * x; 
    } else { 
        x = 1; y = 0; 
    } 
    return d;
}
template<typename T> T mod_inverse(T a, T m) {
    T x, y;
    exgcd(a, m, x, y);
    return (m + x % m) % m;
}

ll mod_pow(ll x, ll n, ll mod) { 
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
    // return b ? qpow(a * a % mod, b >> 1, mod) * (b & 1 ? a : 1) % mod : 1;
}
ll fact[1000000 + 10];
void init() {
    fact[0] = 1;
    for (int i = 1; i <= 1000000; ++i)
        fact[i] = fact[i - 1] * i % MOD;
}
ll mod_fact(ll n, ll p, ll &e) {
    e = 0;
    if (n == 0) return 1;

    ll res = mod_fact(n / p, p, e);
    e += n / p;

    if (n / p % 2 != 0) return res * (p - fact[n % p]) % p;
    return res * fact[n % p] % p;
}
ll mod_comb(ll n, ll k, ll p) {
    if (n < 0 || k < 0 || n < k) return 0;
    if (n == 0) return 1;
    ll e1, e2, e3;
    ll a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n - k, p, e3);
    if (e1 > e2 + e3) return 0;
    return a1 * mod_inverse(a2 * a3 % p, p) % p;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    init();
    while (t--) {
        scanf("%lld%lld%lld", &n, &m, &k);
        ll res = n - m - m * k;
        if (m == 1ll) printf("%lld\n", n);
        else 
            if (res < 0) printf("0\n");
            else {
                ll ans = mod_comb(m + res - 1, res, MOD) * n % MOD * mod_inverse(m, MOD) % MOD;
                printf("%lld\n", ans);
            }
    }    
    return 0;
}