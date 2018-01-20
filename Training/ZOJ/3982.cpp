// written at 08:19 on 07 Nov 2017
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 2 * 1e6 + 10;

int T, n;
ll b0, A, B;
ll a[maxn], b[maxn], fact[maxn], iact[maxn], p, cat[maxn], cnt[maxn];

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll inv(int n) {
    if (n == 1) return 1;
    else return (p - (p / n) * inv(p % n) % p) % p;
}

void init() {
    a[0] = 0; b[0] = b0;
    for (int i = 1; i <= 2 * n; i++) {
        b[i] = (A * b[i - 1] + B) % p;
        a[i] = (a[i - 1] + b[i] + 1) % p;
    }

    fact[0] = 1;
    for (int i = 1; i <= 2 * n; i++)
        fact[i] = fact[i - 1] * i % p;
    iact[2 * n] = mod_pow(fact[2 * n], p - 2, p);
    for (int i = 2 * n - 1; i >= 0; i--)
        iact[i] = iact[i + 1] * (i + 1) % p;
}

void solve() {
    for (int i = 0; i <= n; i++)
        cat[i] = fact[2 * i] * iact[i + 1] % p * iact[i] % p;
    cnt[1] = cat[n];
    for (int i = 2; i <= n; i++) {
        if (i & 1) cnt[i] = cnt[i - 1];
        else cnt[i] = (cnt[i - 1] - (cat[n - i / 2] * cat[i / 2 - 1] % p) + p) % p;
    }
    for (int i = 1; i <= n; i++)
        cnt[i] = (2 * cnt[i] - cnt[1] + p) % p;
    for (int i = n + 1; i <= 2 * n; i++)
        cnt[i] = -cnt[2 * n - i + 1];

    ll ans = 0;
    for (int i = 1; i <= 2 * n; i++)
        ans = (ans - cnt[i] * a[i] % p + p) % p;
    ans = ans * inv(cat[n]);
    printf("%lld\n", (ans % p + p) % p);
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%lld%lld%lld%lld", &n, &p, &b0, &A, &B);
        init(); solve();
    }
    return 0;
}
