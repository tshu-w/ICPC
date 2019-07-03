// written at 15:46 on 26 Feb 2017 
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
const int MAX_N = 2e5 + 10;

int N, A[MAX_N], B[MAX_N], k;
vector<Pii> v;
ll ans = 0;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &N, &k);
    rep(i, 0, N) scanf("%d", A + i);
    rep(i, 0, N) scanf("%d", B + i);
    rep(i, 0, N) v.emplace_back(A[i] - B[i], i);
    sort(v.begin(), v.end());
    rep(i, 0, k) ans += A[v[i].second];
    rep(i, k, N) if (v[i].first > 0) ans += A[v[i].second] - v[i].first; else ans += A[v[i].second];
    cout << ans << endl;
    return 0;
}