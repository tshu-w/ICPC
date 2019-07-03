// written at 08:27 on 21 Feb 2017 
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e6 + 10;

int n, m, k, fm;
int f[MAX_N];
Pii s[MAX_N];
vector<int> ans;

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &m, &k);
    rep(i, 0, n) scanf("%d", f + i), fm = max(fm, f[i]);
    rep(i, 0, m) scanf("%d", &s[i].first), s[i].second = i + 1;
    sort(f, f + n); sort(s, s + m);
    rep(i, 0, fm + 1) {
        int r = upper_bound(f, f + n, i) - f;
        if ((ll)r > (ll)k * (i + 1)) return cout << -1 << endl, 0;
        int l = lower_bound(f, f + n, i) - f;
        if (r - l > k) rep(j, l, r - k) f[j] = i - 1;
    }
    int fi = 0, si = 0, day = 0;
    while (fi < n || si < m) {
        rep(i, 0, k) {
            while (si < m && s[si].first < day) ++si;
            if (fi < n && si < m) {
                if (f[fi] <= s[si].first) ++fi; else ans.push_back(s[si++].second);
            } else if (fi == n && si < m) ans.push_back(s[si++].second);
            else if (si == m && fi < n) ++fi;
        }
        ++day;
    }
    printf("%d\n", (int)ans.size());
    sort(begin(ans), end(ans));
    if (ans.size()) { for (auto x : ans) printf("%d ", x);printf("\n");}
    return 0;
}