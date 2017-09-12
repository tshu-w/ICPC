// written at 14:18 on 13 Aug 2017
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

int n, m;
Pii p[maxn];

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; i++)
            scanf("%d%d", &p[i].first, &p[i].second);
        sort(p, p + n);
        int s = 0, t = 0, cnt = 0, last = p[s].first - 1, ans = 0;
        for (;s < n && t < n;) {
            while (t < n && cnt + max(p[t].first - last - 1, 0) <= m) {
                cnt += max(p[t].first - last - 1, 0);
                last = max(last, p[t].second);
                t++;
            }
            ans = max(ans, last - p[s].first + 1 + m - cnt);
            cnt -= max(p[s + 1].first - p[s].second - 1, 0);
            s++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
