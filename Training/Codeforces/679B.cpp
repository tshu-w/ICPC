#include <bits/stdc++.h>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e6 + 5;
const double eps = 1e-10;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
inline T pow3(T a) { return a * a * a;};
ll m;
int cnt = 0;
pair<ll, ll> ans;

void rec(ll m, ll steps, ll subtracted) {
    if (m == 0) {
        ans = max(ans, make_pair(steps, subtracted));
        return;
    }
    ll x = 1;
    while (pow3(x + 1) <= m) ++x;
    rec(m - pow3(x), steps + 1, subtracted + pow3(x));
    if (x - 1 >= 0)
        rec(pow3(x) - 1 - pow3(x - 1), steps + 1, subtracted + pow3(x - 1));
}
int main(int argc, char const *argv[])
{
    cin >> m;
    rec(m, 0, 0);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}