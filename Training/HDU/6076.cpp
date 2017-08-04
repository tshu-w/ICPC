// written at 14:34 on 04 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename "1010"
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";
};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 6e4 + 15;

int t, n, k, A[MAX_N], B[MAX_N], dp[MAX_N][25];
vector<int> m[MAX_N];

int solve(int a, int b) {
    if (a == 0 || b == 0) return a + b;
    if (abs(A[a] - B[b]) > k) return solve(a - 1, b - 1) + 1;
    int c = lower_bound(m[A[a]].begin(), m[A[a]].end(), b) - m[A[a]].begin();
    if (!dp[a][c]) return dp[a][c] = min(solve(a - 1, b), solve(a, b - 1)) + 1;
    return dp[a][c];
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) m[i].clear();
        for (int i = 1; i <= n; i++) scanf("%d", A + i);
        for (int i = 1; i <= n; i++) scanf("%d", B + i);
        for (int i = 1; i <= n; i++)
            for (int j = -k; j <= k; j++)
                if (1 <= B[i] + j && B[i] + j <= n)
                    m[B[i] + j].push_back(i);
        printf("%d\n", solve(n, n));
    }
    return 0;
}
