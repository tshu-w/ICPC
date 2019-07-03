// written at 20:38 on 06 Sep 2017
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

const int maxn = 3e5 + 10;

int n, k, C[maxn], ans[maxn];
ll tot;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", C + i);
    priority_queue<Pii> que;
    for (int i = 1; i <= k; i++)
        que.push(Pii(C[i], i));
    for (int i = 1; i <= n; i++) {
        if (k + i <= n) que.push(Pii(C[k + i], k + i));
        Pii p = que.top(); que.pop();
        ans[p.second] = k + i;
        tot += 1ll * (k + i - p.second) * p.first;
    }
    printf("%lld\n", tot);
    for (int i = 1; i <= n; i++)
        printf("%d%c", ans[i], " \n"[i == n]);
    return 0;
}
