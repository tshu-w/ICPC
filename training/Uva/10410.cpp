// written at 17:27 on 08 Sep 2017
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

const int maxn = 1e3 + 10;

int n, pos[maxn], st[maxn], t;
vector<int> G[maxn];

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0, q; i < n; i++) scanf("%d", &q), pos[q] = i, G[i].clear();
        scanf("%d", &st[0]); t = 1;
        for (int i = 1, q; i < n; i++) {
            scanf("%d", &q);
            while (t > 1 && pos[q] <= pos[st[t - 1]] + 1) --t;
            G[st[t - 1] - 1].push_back(q);
            st[t++] = q;
        }
        for (int i = 0; i < n; i++) {
            printf("%d:", i + 1);
            for (auto x : G[i]) printf(" %d", x);
            puts("");
        }
    }
    return 0;
}
