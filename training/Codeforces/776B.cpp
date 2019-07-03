// written at 22:17 on 23 Feb 2017 
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
const int MAX_N = 1e5 + 10;

int N, color[MAX_N], ans = 1;

int prime[MAX_N];
bool isPrime[MAX_N + 1];
int seive(int n) {
    int p = 0;
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; ++i) 
        if (isPrime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) isPrime[j] = false;
        }
    return p;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    seive(N + 1);

    rep(i, 0, N) {
        if (isPrime[i + 2]) color[i] = 1;
        else color[i] = 2, ans = 2;
    }
    printf("%d\n", ans);
    rep(i, 0, N) printf("%d ", color[i]);
    printf("\n");
    return 0;
}