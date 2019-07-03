// written at 22:28 on 12 Aug 2017
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

const int maxn = 1e2 + 10;

int n, k, A[maxn];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", A + i);
    int cnt = 0, tot = 0;
    for (int i = 0; i < n; i++) {
        tot += A[i];
        cnt += min(tot, 8);
        tot -= min(tot, 8);
        if (cnt >= k) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("%d\n", -1);
    return 0;
}
