// written at 09:45 on 22 Feb 2017 
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
const int MAX_N = 1e5 + 10;

int s, x1, x2, t1, t2, p, d, ans, dd;

int main(int argc, char const *argv[])
{
    cin >> s >> x1 >> x2;
    cin >> t1 >> t2;
    cin >> p >> d;
    ans = abs(x1 - x2) * t2;
    if (x1 < x2) dd = 1; else dd = -1;
    int dis = 0;
    if (t1 < t2) {
        if (d == 1) {
            if (dd == 1)
                if (p <= x1) ans = min(ans, (x2 - p) * t1);
                else ans = min(ans, (x2 + 2 * s - p) * t1);
            else 
                ans = min(ans, (2 * s - p - x2) * t1);
        } else {
            if (dd == -1)
                if (p >= x1) ans = min(ans, (p - x2) * t1);
                else ans = min(ans, (p + 2 * s - x2) * t1);
            else ans = min(ans, (p + x2) * t1);
        }
    }
    cout << ans << endl;
    return 0;
}