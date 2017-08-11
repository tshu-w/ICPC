// written at 20:05 on 09 May 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 1e3 + 10;

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        bool flag = true;
        int n;
        Pii p[MAX_N];
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p[i].first, &p[i].second);
        }
        sort(p, p + n);
        int mid = p[0].first + p[n - 1].first;
        for (int i = 0; i < n && flag; i++) {
            Pii pp = p[i];
            pp.first = mid - p[i].first;
            if (*lower_bound(p, p + n, pp) != pp) flag = false;
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
