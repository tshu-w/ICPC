// written at 09:04 on 21 Feb 2017 
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
const ull B = 1e8 + 7;

int n, k, x, A[MAX_N], cnt = -1, AA[MAX_N], st;
set<ull> s;
map<ull, int> mp;

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &k, &x);
    rep(i, 0, n) scanf("%d", A + i), AA[i] = A[i];
    sort(AA, AA + n);
    ull h = 0; rep(j, 0, n) h = h * B + (ll)AA[j]; s.insert(h);
    rep(i, 0, k - 1) {
        sort(AA, AA + n);
        for (int j = 0; j < n; j += 2) AA[j] ^= x;
        ull h = 0; 
        rep(j, 0, n) h = h * B + (ll)AA[j];
        if (i && s.find(h) != s.end()) {
            cnt = i + 1 - mp[h], st = i + 1; break;
        } else s.insert(h), mp[h] = i + 1;
    }
    if (cnt != -1) k = (k - st) % cnt;
    rep(i, 0, st + k) {
        sort(A, A + n);
        for (int j = 0; j < n; j += 2) A[j] ^= x;
    }
    sort(A, A + n);
    printf("%d %d\n", A[n - 1], A[0]);
    return 0;
}