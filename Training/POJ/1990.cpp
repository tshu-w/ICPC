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

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;
typedef pair<ll, ll > Pll;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e6 + 10;

int N, cnt[MAX_N + 1];
ll bit[MAX_N + 1], ans;
Pii p[MAX_N];

template <typename T>
T sum(T *b, int i) {
    T res = 0;
    while (i) {
        res += b[i];
        i -= i & -i;
    }
    return res;
}
template <typename T>
void add(T *b, int i, T x) {
    while (i <= MAX_N) {
        b[i] += x;
        i += i & -i;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d%d", &p[i].first, &p[i].second);
    sort(p, p + N);
    for (int i = 0; i < N; ++i) {
        int lcnt = sum(cnt, p[i].second), rcnt = i - lcnt;
        ll lsum = sum(bit, p[i].second), rsum = sum(bit, MAX_N) - lsum;
        ans += (((ll)lcnt * p[i].second - lsum) + (rsum - (ll)rcnt * p[i].second)) * p[i].first;
        add(cnt, p[i].second, 1); add(bit, p[i].second, (ll)p[i].second);
    }
    printf("%lld\n", ans);
    return 0;
}