// written at 14:52 on 27 Feb 2017 
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
const int MAX_N = 30 + 10;

int N, M, L, R, S[MAX_N];

int main(int argc, char const *argv[])
{
    while (~scanf("%d%d%d%d", &N, &M, &L, &R)) {
        L = (int)(L / (2 * pi * R)) + 1;
        rep(i, 0, N) scanf("%d", S + i), S[i] = ((int)(S[i] / (2 * pi * R)) + 1) % L;
        bool flag = true;
        rep(i, 0, MAX_N) {
            int res = 0;
            rep(j, 0, N) if (S[j] >> i & 1) ++res;
            if (res % (M + 1)) {flag = false; break;}
        }
        puts(!flag? "Alice" : "Bob");
    } 
    return 0;
}