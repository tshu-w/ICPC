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
const int MAX_N = 1e6;

template <typename T>
inline T sqr(T a) { return a * a;};

int prime[MAX_N];
bool is_prime[MAX_N + 1];
int seive(int n) {
    int p = 0;
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) 
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    return p;
}

int main(int argc, char const *argv[])
{
    int t, a, b;
    cin >> t;
    int p = seive(1e6);
    while (t--) {
        scanf("%d%d", &a, &b);
        for (int i = 0; i < p; ++i)
            if (a / b % prime[i] != 0) {
                printf("%d\n", prime[i] * b);
                break;
            }
    } 
    return 0;
}