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
const int MAX_N = 5e4 + 10;

int K, N, M, S[MAX_N], T[MAX_N];
int n, k, sa[MAX_N * 2], rnk[MAX_N * 2], tmp[MAX_N * 2], lcp[MAX_N * 2];

bool cmp_sa(int i, int j) {
    if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
    else {
        int ri = i + k <= n? rnk[i + k] : -1;
        int rj = j + k <= n? rnk[j + k] : -1;
        return ri < rj;
    }
}
void construct_sa(const int *S, int *sa) {
    n = N + M + 1;
    for (int i = 0; i <= n; i++) {
        sa[i] = i;
        rnk[i] = i < n? S[i] : -1;
    }
    for (k = 1; k <= n; k *= 2) {
        sort(sa, sa + n + 1, cmp_sa);
        tmp[sa[0]] = 0;
        for (int i = 1; i <= n; i++)
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp_sa(sa[i - 1], sa[i])? 1 : 0);
        memcpy(rnk, tmp, (n + 1) * sizeof(int));
    }
}
void construct_lcp(const int *S, int *sa, int *lcp) {
    for (int i = 0; i <= n; i++) rnk[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; i++) {
        int j = sa[rnk[i] - 1];
        if (h > 0) h--;
        for (; j + h < n && i + h < n; h++)
            if (S[j + h] != S[i + h]) break;
        lcp[rnk[i] - 1] = h;
    }
}

int count(int K) {
    int res = 0, x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (lcp[i] < K) {
            if (y > 0) res += x;
            x = y = 0;
        }
        if (sa[i + 1] < N) ++x; else ++y;
    }
    return res;
}
 
void solve() {
    S[N] = INF / 3;
    memcpy(S + N + 1, T, sizeof(int) * M);
    construct_sa(S, sa);
    construct_lcp(S, sa, lcp);
    printf("%d\n", count(K) - count(K + 1));
}

int main() {
    while (~scanf("%d%d%d", &N, &M, &K)) {
        for (int i = 0; i < N; i++)
            scanf("%d", S + i);
        for (int j = 0; j < M; j++)
            scanf("%d", T + j);
        solve();
    }
    return 0;
}