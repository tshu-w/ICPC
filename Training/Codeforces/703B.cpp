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
int c[MAX_N], n, k, a[MAX_N];
ll sum, ans, asum, res;
int main(int argc, char const *argv[])
{
    cin >> n >> k;    
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        sum += c[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> a[i]; --a[i];
        asum += c[a[i]];
    }
    for (int i = 0; i < n; ++i) {
        ans += c[i] * c[(i + 1) % n];
    }
    for (int i = 0; i < k; ++i) {
        ans -= c[a[i]] * (c[(a[i] + 1) % n] + c[(a[i] - 1 + n) % n]);
        ans += c[a[i]] * (sum - c[a[i]]);
        res += (asum - c[a[i]]) * c[a[i]];
    }
    ans -= res / 2;
    for (int i = 1; i < k; ++i)
        if (a[i - 1] + 1 == a[i]) 
            ans += c[a[i]] * c[a[i - 1]];
    if ( ((a[k - 1] + 1) % n) == a[0])
        ans += c[a[k - 1]] * c[a[0]];
    cout << ans << endl;
    return 0;
}