// written at 20:37 on 27 Jul 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
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

const int MAX_N = 3000 + 10;

int n, A[MAX_N], t, L[MAX_N], R[MAX_N], tot, ans;
int minN[MAX_N][MAX_N], maxN[MAX_N][MAX_N], f[MAX_N][MAX_N], last[MAX_N];
Pii p[MAX_N];

int solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", A + i);
        p[i].first = i, p[i].second = A[i];
        if (p[i].first > p[i].second) swap(p[i].first, p[i].second);
    }
    sort(p + 1, p + n + 1);
    int l, r;
    l = r = 1;
    tot = ans = 0;
    for (int i = 1; i <= n; i++) {
        r = max(r, p[i].second);
        if (r == i) {
            L[tot] = l; R[tot++] = r;
            l = r = i + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        f[i][i] = 1;
        last[i] = i;
        minN[i][i] = maxN[i][i] = A[i];
        for (int j = i + 1; j <= n; j++) {
            minN[i][j] = min(minN[i][j - 1], A[j]);
            maxN[i][j] = max(maxN[i][j - 1], A[j]);
        }
    }
    for (int k = 2; k <= n; k++) {
        for (int i = 1; i <= n - k + 1; i++) {
            int j = i + k - 1;
            if (maxN[i][j] - minN[i][j] != j - i) f[i][j] = 0;
            else {
                if (minN[i][j] < minN[i][last[i]]) f[i][j] = 1;
                else f[i][j] = f[i][last[i]] + f[last[i] + 1][j];
                last[i] = j;
            }
            // cout << i << " " << j << " " << f[i][j] << endl;
        }
    }

    ans = tot;
    for (int i = 0; i < tot; i++) {
        // cout << L[i] << " " << R[i] << endl;
        for (int x = L[i]; x < R[i]; x++) {
            if (maxN[L[i]][x] - minN[L[i]][x] != x - L[i] || maxN[L[i]][x] != R[i]) continue;
            for (int y = R[i]; y > x; y--) {
                if (maxN[y][R[i]] - minN[y][R[i]] != R[i] - y || minN[y][R[i]] != L[i]) continue;
                // cout << x << " " << y << endl;
                ans = max(ans, tot + f[x + 1][y - 1] + 1);
            }
        }
    }

    return ans;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        printf("%d\n", solve());
    }
    return 0;
}
