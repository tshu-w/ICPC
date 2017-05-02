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
const int INF = INT_MAX;
const int MAX_N = 1000 + 10;
const ll MOD = 1e9 + 7;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, cs = 0, n, m, a[MAX_N], A[MAX_N];
ll bit[MAX_N][MAX_N + 1];

int compress(int *A) {
    vector<int> v;
    for (int i = 0; i < n; ++i)
        v.push_back(A[i]);
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for (int i = 0; i < n; ++i)
        a[i] = lower_bound(v.begin(), v.end(), A[i]) - v.begin() + 1;
    
    return v.size() + 1;
}

ll sum(int index, int i) {
    ll s = 0;
    while (i > 0) {
        s += bit[index][i];
        if (s > MOD) s -= MOD;
        i -= i & -i;
    }
    return s;
}
void add(int index, int i, ll x) {
    while (i <= n) {
        bit[index][i] += x;
        if (bit[index][i] > MOD) bit[index][i] -= MOD;
        i += i & -i;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            scanf("%d", A + i);
        compress(A);

        memset(bit, 0, sizeof bit);

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= min(i + 1, m); ++j) {
                ll res = 0;
                if (j == 1)
                    res = 1;
                else {
                    res += sum(j - 1, a[i] - 1);
                    if (res > MOD) res -= MOD;
                }
                add(j, a[i], res);
                // cout << "dp[" << i << ", " << j << "]=" << res << " " << ans[j] << endl;
            }
        }
        printf("Case #%d: %lld\n", ++cs, sum(m, n));
    }
    return 0;
}