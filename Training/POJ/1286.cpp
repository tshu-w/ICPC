// written at 14:44 on 22 Feb 2017 
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

int N;
ll ans;

ll power(int x, int n) {
    ll res = 1;
    while (n) {
        if (n & 1) res *= x;
        x = x * x;
        n >>= 1;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    while(scanf("%d", &N) && N != -1) {
        ans = 0;
        if (!N) {printf("%lld\n", ans); continue;}
        for (int i = 1; i <= N; ++i) ans += power(3, __gcd(N, i));
        if (N & 1) ans += N * power(3, (N + 1) / 2);
        else ans += N * (power(3, N / 2) + power(3, N / 2 + 1)) / 2ll;
        printf("%lld\n", ans / (2 * N));
    }
    return 0;
}