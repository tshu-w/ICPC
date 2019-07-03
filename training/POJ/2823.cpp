// written at 14:15 on 1 Mar 2017 
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
const int MAX_N = 1e6 + 10;

int N, k, A[MAX_N], B[MAX_N], deq[MAX_N];

bool cmp(int a, int b, int f) {
    if (f) return a <= b;
    else return a >= b;
}
void solve(int f) {
    int s = 0, t = 0;
    for (int i = 0; i < N; ++i) {
        while (s < t && cmp(A[deq[t - 1]], A[i], f)) --t;
        deq[t++] = i;
        if (i - k + 1 >= 0) {
            B[i - k + 1] = A[deq[s]];
            if (deq[s] == i - k + 1) ++s;
        }
    }

    for (int i = 0; i <= N - k; ++i)
        printf("%d%c", B[i], " \n"[i == N - k]);
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &N, &k);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    solve(0); solve(1);
    return 0;
}