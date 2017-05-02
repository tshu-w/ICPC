// written at 17:51 on 24 Feb 2017 
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

int N, M, A[MAX_N], k, l, r, v[MAX_N];

int main(int argc, char const *argv[])
{
    scanf("%d%d", &N, &M);
    rep(i, 0, N) rep(j, 0, M) scanf("%d", &A[i * M + j]);
    rep(i, 0, N) v[i] = i + 1;
    rep(j, 0, M) {
        int last = 0, cur = 1;
        while (last < N) {
            while (cur < N && A[cur * M + j] >= A[(cur - 1) * M + j]) ++cur;
            rep(i, last, cur) v[i] = max(v[i], cur);
            last = cur;
            cur = cur + 1;
        }
    }
    scanf("%d", &k);
    rep(i, 0, k) {
        scanf("%d%d", &l, &r);--l;
        if (v[l] >= r) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}