// written at 23:08 on 17 Aug 2018
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

const int maxn = 2e5 + 10;

int n, q, a[maxn], l, r;
vector<int> v[maxn];

int bit[maxn];
int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
void add(int i, int x) {
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

int main() {
    scanf("%d%d", &n, &q); int fst = -1;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (a[i] == q) flag = true;
        if (fst == -1 && a[i]) fst = a[i];
    }
    for (int i = 1, pre = -1; i <= n; i++) {
        if (a[i] == 0) {
            if (!flag) a[i] = q, flag = true;
            else if (pre == -1) a[i] = fst;
            else a[i] = pre;
        }
        pre = a[i];
        v[a[i]].push_back(i);
    }
    for (int i = 1; i <= q && flag; i++) {
        sort(v[i].begin(), v[i].end());
        if (!v[i].empty() && sum(v[i].back()) - sum(v[i].front()) > 0) flag = false;
        for (auto pos : v[i]) add(pos, 1);
    }
    if (flag) {
        puts("YES");
        for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
    } else puts("NO");
    return 0;
}
