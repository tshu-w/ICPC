// written at 17:08 on 09 May 2017
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

int main(void) {
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; _++) {
        int n;
        scanf("%d", &n);
        vector<int> v(n), vv(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        bool flag = true;
        for (int i = 0; i < 1000 + 10; i++) {
            for (int j = 0; j + 1 < n; j++)
                vv[j] = abs(v[j] - v[j + 1]);
            vv[n - 1] = abs(v[n - 1] - v[0]);
            bool zero = true;
            for (int j = 0; j < n; j++)
                if (vv[j] != 0) {
                    zero = false;
                    break;
                }
            if (zero) {
                flag = false;
                break;
            }
            v = vv;
        }
        puts(flag ? "LOOP" : "ZERO");
    }
    return 0;
}
