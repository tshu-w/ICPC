// written at 22:32 on 19 Jan 2017 
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
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e5 + 10;

ll n, m, k, x, y, imx, imn, sg, total;

int main(int argc, char const *argv[])
{
    cin >> n >> m >> k >> x >> y;
    if (n == 1 || n == 2) {
        total = n * m;
        imn = k / total;
        imx = imn + (k % total? 1 : 0);
        sg = imn + (k % total >= (x - 1) * m + y? 1 : 0);
    } else {
        total = (2 * n - 2) * m;
        imn = k / total;
        imx = 2 * imn;
        if (x == 1 || x == n) sg = imn; else sg = imx;
        k %= total;
        total = n * m;
        imn += k / total;
        if (k > total) imx += 2;
        else if (k > m) imx += 1;
        else if (imx == imn && k) imx += 1;
        if (x == 1 || x == n) {
            if (k >= (x - 1) * m + y) sg += 1;
        } else {
            if (k >= n * m + (n - x - 1) * m + y) sg += 2;
            else if (k >= (x - 1) * m + y) sg += 1;
        }
    }
    cout << imx << " " << imn << " " << sg << endl;
    return 0;
}