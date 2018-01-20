// written at 18:55 on 16 Oct 2017
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

int n, k, m, A[maxn], cnt[maxn];

int main() {
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", A + i);
        cnt[A[i] % m]++;
    }
    bool flag = false;
    int kk = -1;
    for (int i = 0; i < m; i++) if (cnt[i] >= k) {flag = true; kk = i; break;}
    if (flag) {
        printf("Yes\n");
        for (int i = 0, j = 0; i < n && j < k; i++) {
            if (A[i] % m == kk) printf("%d%c", A[i], " \n"[++j == k]);
        }
    } else printf("No\n");
    return 0;
}
