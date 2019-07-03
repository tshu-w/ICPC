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

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e6 + 10;

int T;
ll N;

int main(int argc, char const *argv[])
{
    scanf("%d", &T);    
    for (int i = 1; i <= T; ++i) {
        scanf("%lld", &N);
        ll lb = 1, ub = sqrt(2 * N) + 1;
        while (lb + 1 < ub) {
            ll mid = (lb + ub) / 2;
            if (mid * (mid + 1) / 2 <= N) lb = mid;
            else ub = mid;
        }
        printf("Case #%d: %lld\n", i, lb * (lb + 1) / 2);
    }
    return 0;
}