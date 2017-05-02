// written at 17:43 on 17 Jan 2017 
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
const int MAX_V = 500 + 10;

int S, T, V, E, mc;
int wet[MAX_V], G[MAX_V][MAX_V];
bool cmb[MAX_V], vis[MAX_V];

void search() {
    memset(vis, false, sizeof vis);
    memset(wet, 0, sizeof wet);
    S = T = -1;
    int imax, tmp;
    rep(i, 0, V) {
        imax = -INF;
        rep(j, 0, V)
            if (!cmb[j] && !vis[j] && wet[j] > imax) {
                imax = wet[j];
                tmp = j;
            }
        if (T == tmp) return;
        S = T; T = tmp;
        mc = imax;
        vis[tmp] = true;
        rep(j, 0, V) 
            if (!cmb[j] && !vis[j])
                wet[j] += G[tmp][j];
    }
}
int stoer_wagner() {
    memset(cmb, false, sizeof cmb);
    int ans = INF;
    rep(i, 0, V - 1) {
        search();
        ans = min(ans, mc);
        if (ans == 0) return 0;
        cmb[T] = true;
        rep(j, 0, V)
            if (!cmb[j]) {
                G[S][j] += G[T][j];
                G[j][S] += G[j][T];
            }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    while (~scanf("%d%d", &V, &E)) {
        memset(G, 0, sizeof G);
        rep(i, 0, E) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            G[a][b] += c;
            G[b][a] += c;
        }
        printf("%d\n", stoer_wagner());
    }
    return 0;
}

