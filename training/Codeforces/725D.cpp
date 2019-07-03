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
typedef pair<ll, ll > Pll;

const double pi = acos(-1.0);
const ll INF = LLONG_MAX;
const int MAX_N = 300000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, ans = INT_MAX;
ll w0, t0;
bool flag[MAX_N];
vector<Pll> v;
multiset<ll> s;

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    scanf("%I64d%I64d", &t0, &w0);
    for (int i = 1; i < N; ++i) {
        ll t, w;
        scanf("%I64d%I64d", &t, &w);
        v.push_back(Pll(t, w));
    }
    // v.push_back(Pll(t0, w0));
    sort(v.begin(), v.end());
    int crt, last = v.size();
    while (t0 >= 0) {
        crt = lower_bound(v.begin(), v.end(), Pll(t0, INF)) - v.begin();
        // cout << "crt " << crt << " last " << last << endl;
        for (int i = crt; i < last; ++i) {
            s.insert(v[i].second - v[i].first + 1);
        }
        ans = min(ans, (int)s.size() + 1);
        // cout << "Paiming " << ans << endl;
        int flag = false;
        for (auto it = s.begin(); it != s.end(); ++it) {
            ll res = *it;
            // cout << *it << endl;
            if (res <= t0) {
                t0 -= res;
                // cout << t0 << endl;
                s.erase(it);
                flag = true;
                break;
            }
        }
        if (!flag) break;
        last = crt;
    }
    printf("%d\n", ans);
    return 0;
}