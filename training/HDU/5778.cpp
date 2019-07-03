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
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

ll ans;
int t, q;
ll x, y;

bool check(ll n) {
    if (n < 2) return false;
    ll res = n;
    for (ll i = 2; i * i <= n; ++i) 
        if (n % i == 0) {
            if (n % (i * i) == 0) 
                return false;
            n /= i;
        }

    ans = min(ans, abs(res * res - x));
    return true;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &x);
        y = (ll)(sqrt(x) + 0.5);
        ans = INF;
        bool flag = false;
        for (int i = 0; !flag; ++i) {
            flag |= check(y + i);
            flag |= check(y - i);
        }
        printf("%lld\n", ans);
    }    
    return 0;
}