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

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e3 + 10;

int T, R, S, B, x, y, tt;
bool flag[MAX_N][MAX_N];

int main(int argc, char const *argv[])
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &R, &S);
        memset(flag, false, sizeof flag);
        scanf("%d", &B);
        for (int i = 0; i < B; ++i)
            scanf("%d%d", &x, &y), flag[x][y] = true;
        int imin = 0, imax = 0;
        for (int i = 0; i < R; ++i) {
            int last = -1, cur = 0;
            while (cur < S) {
                cur = last + 1;
                while (cur < S && !flag[i][cur]) ++cur;
                imin += (cur - last + 1) / 3;
                imax += (cur - last) / 2;
                last = cur;
            }
        }
        printf("Case #%d: %d %d\n", ++tt, imax, imin);
    }
    return 0;
}