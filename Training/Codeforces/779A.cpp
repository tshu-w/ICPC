// written at 15:46 on 26 Feb 2017 
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
const int MAX_N = 1e2 + 10;

int N, A[10], B[10], C[10], ans;

int main(int argc, char const *argv[])
{
    cin >> N;
    rep(i, 0, N) {
        int a;
        scanf("%d", &a);
        ++A[a]; ++C[a];
    }
    rep(i, 0, N) {
        int a;
        scanf("%d", &a);
        ++B[a]; ++C[a];
    }
    rep(i, 1, 6) if (C[i] & 1) return printf("-1\n"), 0;
    else ans += abs(C[i] / 2 - A[i]);
    printf("%d\n", ans / 2);
    return 0;
}