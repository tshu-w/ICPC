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
const int MAX_N = 10000 + 10;
const int MAX_M = 10000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, cs = 0, n, m, A[MAX_N], num[MAX_M], vis[MAX_M];

template<typename T> T gcd(T a, T b) {
    //return (b)? gcd(b, a  % b) : a;
    while (b) { T t = a % b; a = b; b = t; } return a;
}

vector<int> divisor(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

int main(void) {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        memset(vis, 0, sizeof vis);
        memset(num, 0, sizeof num);
        vector<int> p = divisor(m);
        sort(p.begin(), p.end());
        for (int i = 0; i < n; ++i) {
            scanf("%d", A + i);
            int d = gcd(A[i], m);
            for (int j = 0; j < p.size(); ++j)
                if (p[j] % d == 0) {
                    vis[j] = 1;
                }
        }
        vis[p.size() - 1] = 0;
        ll ans = 0;
        for (int i = 0; i < p.size(); ++i)
            if (vis[i] != num[i]) {
                ll tmp = m / p[i];
                ans += tmp * (tmp - 1) / 2 * p[i] * (vis[i] - num[i]);
                for (int j = i + 1; j < p.size(); ++j)
                    if (p[j] % p[i] == 0)
                        num[j] += vis[i] - num[i];
            }
        printf("Case #%d: %lld\n", ++cs, ans);
    }    
    return 0;
}