// written at 15:50 on 28 Jul 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename "1007"
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const ll MOD = 1e9 + 7;
const ll inv2 = 500000004;

int T;
ll m, p;

ll phi(ll n) {
    ll res = n;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            for (; n % i == 0; n /= i);
        }
    }
    if (n != 1) res = res / n * (n - 1);
    return res;
}

ll mul(ll a, ll b) {
    ll c = a * b;
    // return c - c / MOD * MOD;
    return c % MOD;
}

void add(ll &a, ll b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &m, &p);
        ll ans = 0;
        for (ll i = 1; i * i <= p - 1; i++)
            if ((p - 1) % i == 0) {
                ll j = (p - 1) / i;
                add(ans, mul((i * phi(i) + (i == 1)) / 2 % MOD, mul(j, j)));
                if (i != j) add(ans, mul((j * phi(j) + (j == 1)) / 2 % MOD, mul(i, i)));
            }
        ans -= mul(mul(p, p - 1), inv2);
        if (ans < 0) ans += MOD;
        static int cs = 0;
        printf("Case #%d: %lld\n", ++cs, mul(ans, m));
    }
    return 0;
}
