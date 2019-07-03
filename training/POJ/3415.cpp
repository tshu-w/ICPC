// written at 13:13 on 18 Mar 2017
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
const int MAX_N = 1e5 + 10;

int K;
string S, T;
int n, k, sa[MAX_N * 2], rnk[MAX_N * 2], tmp[MAX_N * 2], lcp[MAX_N * 2];
int sl, tl;

bool cmp_sa(int i, int j) {
    if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
    else {
        int ri = i + k <= n? rnk[i + k] : -1;
        int rj = j + k <= n? rnk[j + k] : -1;
        return ri < rj;
    }
}
void construct_sa(const string &S, int *sa) {
    n = S.length();
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
void construct_lcp(const string &S, int *sa, int *lcp) {
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

int st[MAX_N][2], top;
ll tot;

ll count(bool flag) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (lcp[i] < K) {
            tot = 0;
            top = 0;
        } else {
            int cnt = 0;
            if ((sa[i] < sl) == flag) {
                ++cnt;
                tot += lcp[i] - K + 1;
            }
            while (top > 0 && lcp[i] <= st[top - 1][0]) {
                --top;
                tot -= st[top][1] * (st[top][0] - lcp[i]);
                cnt += st[top][1];
            }
            if (cnt) {
                st[top][0] = lcp[i];
                st[top++][1] = cnt;
            }
            if ((sa[i + 1] > sl) == flag) {
                res += tot;
            }
        }
    }
    return res;
}

void solve() {
    sl = S.length();
    tl = T.length();
    S += '$' + T;
    construct_sa(S, sa);
    construct_lcp(S, sa, lcp);
    printf("%lld\n", count(true) + count(false));
}

int main() {
    while (~scanf("%d", &K) && K) {
        cin >> S >> T;
        solve();
    }
    return 0;
}
