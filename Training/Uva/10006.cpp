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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 65000 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

ll N;
bool isPrime[MAX_N + 1];
int seive(int n) {
    int p = 0;
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; ++i) 
        if (isPrime[i]) {
            for (int j = 2 * i; j <= n; j += i) isPrime[j] = false;
        }
    return p;
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

int main(int argc, char const *argv[])
{
    seive(MAX_N);
    while(~scanf("%lld", &N) && N) {
        if (isPrime[N]) {
            printf("%lld is normal.\n",N); 
        } else {
            bool flag = true;
            for (ll i  = 2LL; i < N; ++i) {
                if (mod_pow(i, N, N) != i) {
                    flag = false;
                    break;
                }
            }
            if (flag) 
                printf("The number %lld is a Carmichael number.\n", N); 
            else 
                printf("%lld is normal.\n", N);

        }    
    }
    return 0;
}