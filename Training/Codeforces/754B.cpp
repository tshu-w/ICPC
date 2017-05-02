// written at 20:24 on 17 Jan 2017 
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
const int MAX_N = 10;

const int dx[] = {1, 0, -1,  0, 1,  1};
const int dy[] = {0, 1,  0, -1, 1, -1};

const int N = 4;
string mp[MAX_N];

int main(int argc, char const *argv[])
{
    rep(i, 0, N)
        cin >> mp[i];
    rep(i, 0, N)
        rep(j, 0, N) rep(d, 0, 6) {
            bool f = true; int c1 = 0, c2 = 0;
            rep(k, 0, 3) {
                int x = k * dx[d] + i;
                int y = k * dy[d] + j;
                if (x < 0 || x > 3 || y < 0 || y > 3) {
                    f = false;
                    break;
                }
                if (mp[x][y] == '.') ++c1;
                else if (mp[x][y] == 'x') ++c2;
                else f = false;
            }
            if (c2 == 2 && c1 == 1) f = true; else f = false;
            if (f) {
                printf("YES\n");
                return 0;
            }
        }
    printf("NO\n");
    return 0;
}