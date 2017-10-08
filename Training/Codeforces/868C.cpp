// written at 14:54 on 05 Oct 2017
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 1e5 + 10;
const int maxk = 5;

int n, k, A[maxn][maxk], vis[20], cnt[5];
vector<bitset<4>> v;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int j = 0; j < k; j++) {
            scanf("%d", &A[i][j]);
            res = res * 2 + A[i][j];
        }
        if (!vis[res]) {
            vis[res] = 1;
            bitset<4> bs(res);
            v.push_back(bs);
        }
    }
    int m = v.size();
    bool flag = false;
    for (int i = 1; i < 1 << m; i++) {
        memset(cnt, 0, sizeof cnt);
        int res = 0;
        for (int j = 0; j < m; j++)
            if (i >> j & 1) {
                for (int k = 0; k < 4; k++) cnt[k] += v[j][k];
                res++;
            }
        bool tag = true;
        for (int k = 0; k < 4; k++) if (cnt[k] > res / 2) tag = false;
        if (tag) flag = true;
    }
    if (flag) printf("YES\n"); else printf("NO\n");
    return 0;
}
