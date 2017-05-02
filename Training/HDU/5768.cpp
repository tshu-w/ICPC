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
const int MAX_N = 20;

template <typename T>
inline T sqr(T a) { return a * a;};
int N;
ll X, Y, P[MAX_N], A[MAX_N];

// find (x, y) s.t. a x + b y = gcd(a, b) = d
template<typename T> T exgcd(T a, T b, T &x, T &y) {
    T d = a;
    if (b) {
        d = exgcd(b, a % b, y, x);
        y -= a / b * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}
template<typename T> T mod_inverse(T a, T m) {
    T x, y;
    exgcd(a, m, x, y);
    return (m + x % m) % m;
}

ll count(ll l, ll r, ll p, ll a) {
    l += p - a; r += p - a;
    return (r / p - (l - 1) / p);
}

ll cal(vector<int> &v) {
    ll M = 1LL, res = 0;
    for (int i = 0; i < v.size(); ++i)
        M *= P[v[i]];
    for (int i = 0; i < v.size(); ++i) {
        ll Mi, Ti, y;
        Mi = M / P[v[i]];
        Ti = mod_inverse(Mi, P[v[i]]);
        res = (res + A[v[i]] * Mi * Ti) % M;
    }
    return count(X, Y, M, res);
}


int main(int argc, char const *argv[])
{
    int t, cases = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%lld%lld", &N, &X, &Y);
        for (int i = 0; i < N; ++i)
            scanf("%lld%lld", P + i, A + i);
        P[N] = 7; A[N] = 0;
        ll res = count(X, Y, 7, 0);
        for (int i = 1; i < (1 << N); ++i) {
            vector<int> vec;
            for (int j = 0; j < N; ++j)
                if ((i >> j) & 1) vec.push_back(j);
            vec.push_back(N);
            if (vec.size() & 1)
                res += cal(vec);
            else res -= cal(vec);
        }
        printf("Case #%d: %lld\n", ++cases, res);
    }
    return 0;
}