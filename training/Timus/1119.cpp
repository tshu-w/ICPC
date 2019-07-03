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

template <typename T>
inline T sqr(T a) { return a * a;};

const double INF = DBL_MAX; 
const int MAX_N = 1000 + 10;
const int MAX_M = 1000 + 10;

int N, M, K;
bool flag[MAX_N][MAX_M];
double f[MAX_N][MAX_M];

int main(int argc, char const *argv[])
{
    cin >> N >> M;
    cin >> K;
    memset(flag, false, sizeof flag);
    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        flag[x][y] = true;
    }

    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= M; ++j)
            f[i][j] = INF;
    
    f[0][0] = 0.;
    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= M; ++j) {
            if (i) f[i][j] = min(f[i][j], f[i - 1][j] + 100.);
            if (j) f[i][j] = min(f[i][j], f[i][j - 1] + 100.);
            if (flag[i][j]) f[i][j] = min(f[i][j], f[i - 1][j - 1] + 100. * sqrt(2));
        }
    printf("%.f\n", f[N][M]);
    return 0;
}