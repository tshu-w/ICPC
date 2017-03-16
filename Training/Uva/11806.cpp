// written at 14:38 on 11 Mar 2017 
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
const int MAX_K = 500 + 10;
const ll MOD = 1000007;

ll C[MAX_K][MAX_K];

void init() {
    C[0][0] = 1;
    for (int i = 1; i < MAX_K; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
}

int main(int argc, char const *argv[])
{
    int t, N, M, K;
    init();
    scanf("%d", &t);
    for (int _ = 1; _ <= t; ++_) {
        scanf("%d%d%d", &M, &N, &K);
        ll ans = 0;
        for (int S = 0; S < 16; S++) {
            int b = 0, r = M, c = N;
            if (S & 1) ++b, r--;
            if (S & 2) ++b, c--;
            if (S & 4) ++b, r--;
            if (S & 8) ++b, c--;
            if (b & 1) ans = (MOD + ans - C[r * c][K]) % MOD;
            else ans = (ans + C[r * c][K]) % MOD;
        }
        printf("Case %d: %lld\n", _, ans);
    }
    return 0;
}