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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 30;
const int MAX_M = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, M;
char c[MAX_N], tmp[5], s[MAX_M];
double p[MAX_N], dp[MAX_M][MAX_N];

int nxt[MAX_N];
void getNext(const string &str) {
    int len = str.length();
    int j = 0, k;
    k = nxt[0] = -1;
    while (j < len) {
        if (k == -1 || str[j] == str[k]) 
            nxt[++j] = ++k;
        else k = nxt[k];
    }
}

int main(int argc, char const *argv[])
{
    while (~scanf("%d%d", &N, &M) && (N + M)) {
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= N; ++i) {
            scanf("%s%lf", tmp, p + i);
            c[i] = tmp[0];
        }
        scanf("%s", s);
        int len = strlen(s);
        getNext(s);
        dp[0][0] = 1;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < len; ++j) {
                for (int k = 1; k <= N; ++k) {
                    int pos = j;
                    while (pos && s[pos] != c[k]) pos = nxt[pos];
                    if (s[pos] == c[k]) ++pos;
                    dp[i + 1][pos] += dp[i][j] * p[k];
                }
            }
        double ans = 0.;
        for (int i = 0; i <= M; ++i) ans += dp[i][len];
        printf("%.2lf%%\n", ans * 100);    
    }
    return 0;
}