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
const int MAX_N = 1e5 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

int T, X[MAX_N], Y[MAX_N], flag[MAX_N * 2];
ll N, M;
int main(int argc, char const *argv[])
{
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; ++i) {
            scanf("%d%d", &X[i], &Y[i]);
        }
        if (N * (N - 1) > 4 * M - 2) {
            printf("YES\n");
            continue;
        }
        memset(flag, 0, sizeof flag);
        bool ok = false;
        for (int i = 0; i < N && !ok; ++i)
            for (int j = i + 1; j < N && !ok; ++j) {
                int dis = abs(X[j] - X[i]) + abs(Y[j] - Y[i]);
                ++flag[dis];
                if (flag[dis] >= 2) {
                    ok = true;
                    break;
                }
            }
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}