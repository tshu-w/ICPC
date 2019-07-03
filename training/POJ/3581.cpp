// written at 10:17 on 18 Mar 2017
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
const int MAX_N = 2e5 + 10;

int N, A[MAX_N];
int rev[MAX_N * 2], sa[MAX_N * 2];
int n, k, rnk[MAX_N * 2], tmp[MAX_N * 2];

bool cmp_sa(int i, int j) {
    if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
    else {
        int ri = i + k <= n? rnk[i + k] : -1;
        int rj = j + k <= n? rnk[j + k] : -1;
        return ri < rj;
    }
}
void construct_sa(int *S, int M, int *sa) {
    n = M;
    for (int i = 0; i <= n; i++) {
        sa[i] = i;
        rnk[i] = i < n? S[i] : -1;
    }
    for (k = 1; k <= n; k *= 2) {
        sort(sa, sa + n + 1, cmp_sa);
        tmp[sa[0]] = 0;
        for (int i = 1; i <= n; i++)
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp_sa(sa[i - 1], sa[i]) ? 1 : 0);
        memcpy(rnk, tmp, sizeof(int) * (n + 1));
    } 
}

void solve() {
    reverse_copy(A, A + N, rev);
    construct_sa(rev, N, sa); 

    int p1;
    for (int i = 0; i < N; i++) {
        p1 = N - sa[i];
        if (p1 >= 1 && N - p1 >= 2) break;
    }

    int m = N - p1;
    reverse_copy(A + p1, A + N, rev);
    reverse_copy(A + p1, A + N, rev + m);
    construct_sa(rev, m * 2, sa);

    int p2;
    for (int i = 0; i <= 2 * m; i++) {
        p2 = p1 + m - sa[i];
        if (p2 - p1 >= 1 && N - p2 >= 1) break;
    }

    reverse(A, A + p1);
    reverse(A + p1, A + p2);
    reverse(A + p2, A + N);
    for (int i = 0; i < N; i++) 
        printf("%d\n", A[i]);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", A + i);
    solve();
    return 0;
}