// written at 13:10 on 8 Mar 2017 
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
#include <numeric>

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
const int MAX_N = 1e3 + 10;
const int MAX_D = 20;

int ans[MAX_N], n, ex[MAX_D] = {1};

void dfs(int d) {
    if (d > MAX_D) return ;
    for (int i = 0; i <= d; i++) {
        ex[d + 1] = ex[i] + ex[d];
        if (ex[d + 1] < MAX_N && ans[ex[d + 1]] >= d + 1) {
            ans[ex[d + 1]] = d + 1;
            dfs(d + 1);
        } 
        ex[d + 1] = ex[d] - ex[i];
        if (ex[d + 1] > 0 && ans[ex[d + 1]] >= d + 1) {
            ans[ex[d + 1]] = d + 1;
            dfs(d + 1);
        } 
    }
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < MAX_N; i++)
        ans[i] = __builtin_popcount(i) + (30 - __builtin_clz(i));
    dfs(0);
    while (scanf("%d", &n), n) {
        printf("%d\n", ans[n]);
    }
    return 0;
}