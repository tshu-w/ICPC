// written at 22:21 on 03 Aug 2018
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

int n, m, q, cnt[maxn], sum[maxn];
char s[maxn], t[maxn];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    scanf("%s", s); scanf("%s", t);
    for (int i = 0; i <= n - m; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++)
            if (s[i + j] != t[j]) flag = false;
        if (flag) cnt[i] = 1;
        sum[i + 1] = sum[i] + cnt[i];
    }
    for (int i = n - m + 1; i < n; i++) sum[i + 1] = sum[i] + 0;
    for (int i = 0, l, r; i < q; i++) {
        scanf("%d%d", &l, &r);
        if (r - m + 1 >= l -1) printf("%d\n", sum[r - m + 1] - sum[l - 1]);
        else printf("0\n");
    }
    return 0;
}
