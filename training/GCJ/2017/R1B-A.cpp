// written at 08:50 on 26 Apr 2017
// 12 mins
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename "A-large-practice"
#define setfile() freopen(filename".in.txt", "r", stdin); freopen(filename".ans.txt", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans.txt");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

int t, n, d;
double ans;

int main(void) {
    setfile();
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> d >> n;
        ans = 0;
        for (int i = 0; i < n; i++) {
            int k, s;
            cin >> k >> s;
            ans = max(ans, (d - k) / (double)s);
        }
        printf("Case #%d: %f\n", _ + 1, d / ans);
    }
    resetfile();
}
