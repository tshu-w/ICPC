// written at 14:33 on 29 Apr 2017
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

const int MOD = 1e9 + 7;
const int MAX_N = 1e6;

int gcd[100][100];
bool flag[MAX_N];

class PowerEquationEasy
{
public:
    int count(int n) {
        memset(flag, false, sizeof flag);
        for (int i = 1; i < 50; i++)
            for (int j = 1; j < 50; j++)
                gcd[i][j] = __gcd(i, j);
        int ret = (ll) n * n % MOD, dec = 0;
        for (int i = 2; 1; i++) {
            if (i * i > n) {
                ret = (ret + (n - i + 1ll - dec) * n) % MOD;
                break;
            }
            if (flag[i]) continue;
            for (ll j = i; j <= n; j *= i) {
                if (j * j <= n) flag[j] = true;
                else ++dec;
            }

            int mx = 1, tmp = 0; ll cur = i;
            while (cur * i <= n) cur *= i, ++mx;
            for (int a = 1; a <= mx; a++)
                for (int b = 1; b <= mx; b++) {
                    int c = max(a, b) / gcd[a][b];
                    tmp = (tmp + n / c) % MOD;
                }
            ret = (ret + tmp) % MOD;
        }
        return ret;
    }
};
