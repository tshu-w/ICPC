#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif    
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

char sa[MAX_N], sb[MAX_N];
int al, bl, dp[MAX_N][MAX_N];

int main(int argc, char const *argv[])
{
    while (gets(sa) != NULL) {
        gets(sb);
        al = strlen(sa);
        bl = strlen(sb);
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < al; ++i)
            for (int j = 0; j < bl; ++j)
                if (sa[i] == sb[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
        printf("%d\n", dp[al][bl]);
    }
    return 0;
}