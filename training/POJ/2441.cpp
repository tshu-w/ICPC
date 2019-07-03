#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <bitset>

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
const int MAX_N = 20;

int N, M, dp[2][1 << MAX_N];
vector<int> A[MAX_N];

int main(int argc, char const *argv[])
{
    scanf("%d%d", &N, &M);
    rep(i, 0, N) {
        int a, p;
        scanf("%d", &p);
        rep(j, 0, p) scanf("%d", &a), A[i].push_back(--a);
    }
    dp[0][(1 << M) - 1] = 1;
    int *cur = dp[0], *nxt = dp[1];
    rep(i, 0, N) {
        fill(nxt, nxt + (1 << M), 0);
        rep(S, 0, 1 << M) if (cur[S])
            rep(j, 0, A[i].size())
                if (S >> A[i][j] & 1)
                    nxt[S - (1 << A[i][j])] += cur[S];
        swap(cur, nxt);
    }
    int ans = 0;
    rep(S, 0, 1 << M) ans += cur[S];
    printf("%d\n", ans);
    return 0;
}