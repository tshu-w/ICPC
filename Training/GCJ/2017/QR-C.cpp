// written at 17:11 on 8 Apr 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename "C-large-practice"
#define setfile() freopen(filename".in.txt", "r", stdin); freopen(filename".ans.txt", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans.txt");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

int t;
ll n, k, a1, a2;

int main() {
    setfile();
    scanf("%d", &t);
    for (int _ = 0; _ < t; _++) {
        scanf("%lld%lld", &n, &k);
        set<ll> s;
        map<ll, ll> mp;
        ll p = 0;
        mp[n] = 1;
        s.insert(n);
        while (s.size()) {
            ll x = *s.rbegin();
            a1 = (x - 1) / 2;
            a2 = (x - 1) / 2 + (x - 1) % 2;
            p += mp[x];
            if (p >= k) break;
            else {
                s.erase(x);
                s.insert(a1); s.insert(a2);
                mp[a1] += mp[x];
                mp[a2] += mp[x];
            }
        }
        printf("Case #%d: %lld %lld\n", _ + 1, a2, a1);
    }
    return 0;
    resetfile();
}
