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

int main(int argc, char const *argv[])
{
    int N;
    while (~scanf("%d", &N)) {
        double ans = 0., c;
        for (int i = 0; i < N; ++i) {
            scanf("%lf", &c);
            if (i == 0 || i == N - 1)
                ans += c / 2.;
            else ans += c / 3.;
        }
        if (N == 1) ans = ans * 2.;
        printf("%f\n", ans);
    }    
    return 0;
}