// written at 12:10 on 10 Sep 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 1e5 + 10;
const int INF = INT_MAX / 3;

int A[maxn], dp[maxn], t, n, k;
long lis(int n, int flag) {
    fill(dp, dp + n, INF);
    for (int i = 0; i < n; ++i)
        *upper_bound(dp, dp + n, flag * A[i]) = A[i] * flag;// lds: -A[i]; ln: upper_bound
    return lower_bound(dp, dp + n, INF) - dp;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) scanf("%d", A + i);
        int m = max(lis(n, 1), lis(n, -1));
        if (m >= n - k) puts("A is a magic array.");
        else puts("A is not a magic array.");
    }
    return 0;
}
