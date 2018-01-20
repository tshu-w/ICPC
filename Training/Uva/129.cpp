// written at 10:33 on 01 Oct 2017
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename "129"
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

const int maxn = 1e2;
int n, l, A[maxn], cnt;

int dfs(int cur) {
    if (cnt++ == n) {
        for (int i = 0; i < cur; i++) {
            printf("%c%s", 'A' + A[i], i % 4 == 3 && i + 1 != cur && i % 64 != 63? " " : "");
            if (i % 64 == 63 || i + 1 == cur) printf("\n");
        }
        printf("%d\n", cur);
        return 0;
    }
    for (int i = 0; i < l; i++) {
        A[cur] = i;
        bool flag = true;
        for (int j = 1; 2 * j <= cur + 1; j++) {
            bool equal = true;
            for (int k = 0; k < j; k++) equal &= A[cur - k] == A[cur - j - k];
            flag &= !equal;
        }
        if (flag) if (!dfs(cur + 1)) return 0;
    }
    return 1;
}

int main() {
    while (scanf("%d%d", &n, &l) && n + l) {
        cnt = 0;
        dfs(0);
    }
    return 0;
}
