// written at 12:15 on 09 Sep 2017
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

int n, C[maxn], D[maxn], t, b;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &b);
        for (int i = 0; i < n; i++)
            scanf("%d", C + i);
        for (int i = 0; i < n - 1; i++)
            scanf("%d", D + i);
        bool flag = true;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            tot += C[i];
            if (i + 1 != n) {
                tot -= D[i] * b;
                if (tot < 0) {
                    flag = false;
                    break;
                }
            }
        }
        puts(flag? "Yes" : "No");
    }
    return 0;
}
