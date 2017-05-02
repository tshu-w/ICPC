// written at 16:32 on 9 Feb 2017 
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
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;

int N, t, x, y, ans;
Pii xs[MAX_N], ys[MAX_N];
bool vis[MAX_N][2];

bool check(Pii *s, bool flag) {
    int it = 0;
    while (it + 1 < N) {
        if (s[it + 1].first == s[it].first) {
            ans += s[it + 1].second - s[it].second;
            if (flag) {
                rep(i, s[it].second + 1, s[it + 1].second) {
                    int b = lower_bound(xs, xs + N, Pii(i, -INF)) - xs;
                    int e = lower_bound(xs, xs + N, Pii(i + 1, -INF)) - xs;
                    for (int j = b; j < e; j += 2)
                        if (xs[j].second <= s[it].first && s[it].first <= xs[j + 1].second) return false;
                }
            }
            it += 2;
        }
        else return false;
    }
    return true;
}

int dfs(int k, int tp) {
    if (vis[k][tp]) return 0;
    vis[k][tp] = true;
    if (k & 1) k -= 1; else k += 1;
    if (!tp) 
        return dfs(lower_bound(ys, ys + N, Pii(xs[k].second, xs[k].first)) - ys, 1) + 1;
    else return dfs(lower_bound(xs, xs + N, Pii(ys[k].second, ys[k].first)) - xs, 0) + 1;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        rep(i, 0, N) {
            scanf("%d%d", &x, &y);
            xs[i] = Pii(x, y); ys[i] = Pii(y, x);
        }
        ans = 0;
        sort(xs, xs + N); sort(ys, ys + N);
        bool flag = true;
        flag &= check(xs, false);
        flag &= check(ys, true);
        memset(vis, false, sizeof vis);
        flag &= dfs(0, 0) == N;
        printf("%d\n", flag ? ans : -1);
    }
    return 0;
}