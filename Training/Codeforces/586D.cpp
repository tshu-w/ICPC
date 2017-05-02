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
const int MAX_N = 100 + 10;

int N, K, t;
bool dp[3][MAX_N];
char mp[3][MAX_N];

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &N, &K);
        for (int i = 0; i < 3; ++i)
                scanf("%s", mp[i]);
        for (int i = N; i < N + 4; ++i)
            for (int j = 0; j < 3; ++j)
                mp[j][i] = '.';
        memset(dp, false, sizeof dp);
        for (int i = 0; i < 3; ++i)
            if (mp[i][0] == 's')
                dp[i][0] = true;
        bool flag = false;
        for (int i = 0; i < N; i += 3)
            for (int j = 0; j < 3; ++j)
                if (dp[j][i]) {
                        for (int k = -1; k <= 1; ++k)
                            if (0 <= j + k && j + k < 3 && mp[j][i + 1] == '.') {
                                bool ok = true;
                                for (int w = i + 1; w <= i + 3; ++w)
                                    if (mp[j + k][w] != '.')
                                        ok = false;
                                if (ok) {
                                    dp[j + k][i + 3] = true;
                                    if (i + 3 >= N) flag = true;
                                }
                            }
                }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }    
    return 0;
}