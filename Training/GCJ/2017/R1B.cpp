// written at 11:01 on 15 Apr 2017
#include <bits/stdc++.h>

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
const int MAX_N = 100;

int t, n, q, R[MAX_N], Q[MAX_N][MAX_N], ans;
bool flag[MAX_N][MAX_N];
vector<int> v;

int C(vector<int> &v) {
    int k = v[0] / R[0] + (v[0] % R[0] > R[0] / 2 ? 1 : 0);
    for (int i = 0; i < n; i++)
        if (!(R[i] * k * 0.9 <= v[i] && v[i] <= R[i] * k * 1.1))
            return 0;
    return 1;
}

void dfs(int k, int res) {
    if (k == q) {
        ans = max(ans, res);
        return ;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < q; j++)
            if (!flag[m][j]) {
                flag[i][j] = true;
                v.push_back(Q[i][j]);
                if (i + 1 == n) dfs(k + 1, res + C(v));
                v.pop_back();
                flag[i][j] = false;
            }
}

int main(int argc, char const *argv[])
{
    // setfile();
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        ans = 0;
        memset(flag, false, sizeof flag);
        cin >> n >> q;
        for (int i = 0; i < n; i++)
            cin >> R[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < q; j++)
                cin >> Q[i][j];
        dfs(0, 0);
        printf("Case #%d: %d\n", _ + 1, ans);
    }
    // resetfile();
    return 0;
}