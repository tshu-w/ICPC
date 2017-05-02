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
const int MAX_N = 100000 + 10;
const int MOD = 1000000007; 
const ull B = 100000007;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, cases = 0, dp[MAX_N], al, bl;
char a[MAX_N], b[MAX_N];

int main(int argc, char const *argv[])
{
    cin >> t;
    while (t--) {
        scanf("%s%s", a, b);
        al = strlen(a); bl = strlen(b);
        ull t = 1;
        for (int i = 0; i < bl; ++i) t *= B;
        
        ull ah = 0, bh = 0;
        for (int i = 0; i < bl; ++i) ah = ah * B + a[i];
        for (int i = 0; i < bl; ++i) bh = bh * B + b[i];

        memset(dp, 0, sizeof dp); 
        fill(dp, dp + bl, 1);
        for (int i = 0; i + bl <= al; ++i) {
            dp[i + bl] = dp[i + bl - 1];
            if (ah == bh) dp[i + bl] = (dp[i + bl] + dp[i]) % MOD;
            if (i + bl < al)
                ah = ah * B + a[i + bl] - t * a[i];
            // cout << i + bl << " " <<  dp[i + bl] << endl;
        }
        printf("Case #%d: %d\n", ++cases, dp[al]);
    }
    return 0;
}