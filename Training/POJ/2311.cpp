// written at 17:36 on 23 Feb 2017 
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
const int MAX_N = 200 + 10;

int w, h, g[MAX_N][MAX_N];

int grundy(int w, int h) {
    if (g[w][h] != -1) return g[w][h];
    set<int> s;
    for (int i = 2; i + 2 <= w; ++i) s.insert(grundy(i, h) ^ grundy(w - i, h));
    for (int i = 2; i + 2 <= h; ++i) s.insert(grundy(w, i) ^ grundy(w, h - i));
    int res = 0;
    while (s.count(res++));
    return g[w][h] = res - 1;
}

int main(int argc, char const *argv[])
{
    memset(g, -1, sizeof g);
    while (~scanf("%d%d", &w, &h)) {
        puts(grundy(w, h)? "WIN" : "LOSE");
    }    
    return 0;
}