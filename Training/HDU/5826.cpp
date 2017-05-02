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
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

ll V[MAX_N];
int N, Q, C, t, k, T;

int main(int argc, char const *argv[])
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &C);
        for (int i = 0, x, d; i < N; ++i)
            scanf("%lld%d%d", V + i, &x, &d);
        sort(V, V + N);
        scanf("%d", &Q);
        while (Q--) {
            scanf("%d%d", &t, &k); --k;
            printf("%.3f\n", sqrt(sqr(V[k]) + 2. * C * t));
        }
    }    
    return 0;
}