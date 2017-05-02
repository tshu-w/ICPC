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
const int MAX_N = 100;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, N, M;

int main(int argc, char const *argv[])
{
    while (~scanf("%d%d", &N, &M) && N && M) {    
        vector<int> Y[MAX_N];
        for (int i = 0, x, y; i < N * N; ++i) {
            scanf("%d%d", &x, &y);
            Y[x].push_back(y);
        }
        for (int i = 1; i <= N; ++i)
            sort(Y[i].begin(), Y[i].end());
        ll ans = LLONG_MAX;
        for (int s = 1; s + N <= M; ++s) {
            ll res = 0;
            for (int i = 1; i <= N; ++i) {
                for (int j = 0; j < N; ++j)
                    res += abs(Y[i][j] - (s + j));
            }
            ans = min(res, ans);
        }
        printf("%I64d\n", ans);
    }    
    return 0;
}