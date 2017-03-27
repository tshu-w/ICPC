// written at 22:36 on 23 Mar 2017
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
const ll LLINF = LLONG_MAX;
const int MAX_N = 7000 + 10;

int N, k[2], s[2][MAX_N], dp[2][MAX_N], cnt[2][MAX_N];
bool flag[2][MAX_N];

int main() {
    scanf("%d", &N);
    scanf("%d", &k[0]);
    for (int i = 0; i < k[0]; i++)
        scanf("%d", s[0] + i);
    scanf("%d", &k[1]);
    for (int i = 0; i < k[1]; i++)
        scanf("%d", s[1] + i);
    memset(dp, -1, sizeof dp);
    memset(flag, 0, sizeof flag);
    for (int i = 0; i < 2; i++)
        for (int j = 1; j < N; j++)
            cnt[i][j] = k[i];
    dp[0][0] = dp[1][0] = 0;

    while (true) {
        bool change = false;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < N; j++)
                if (!flag[i][j] && dp[i][j] != -1) {
                    flag[i][j] = true;
                    for (int e = 0; e < k[1 - i]; e++) {
                        int pre = (j - s[1 - i][e] + N) % N;
                        if (dp[i][j] == 0) {
                            if (dp[1 - i][pre] == -1) {
                                change = true;
                                dp[1 - i][pre] = 1;
                            }
                        } else {
                            cnt[1 - i][pre]--;
                            if (cnt[1 - i][pre] == 0) {
                                change = true;
                                dp[1 - i][pre] = 0;
                            }
                        }
                    }
                }
        if (!change) break;
    }

    for (int i = 0; i < 2; i++)
        for (int j = 1; j < N; j++) {
            if (dp[i][j] == 1) printf("Win");
            else if (dp[i][j] == 0) printf("Lose");
            else printf("Loop");
            printf("%c", j + 1 == N? '\n' : ' ');
        }
    return 0;
}