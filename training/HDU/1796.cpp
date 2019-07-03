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
const int MAX_M = 15;

template <typename T>
inline T sqr(T a) { return a * a;};

ll N;
int M, A[MAX_M];

template<typename T> T gcd(T a, T b) {
    //return (b)? gcd(b, a  % b) : a;
    while (b) { T t = a % b; a = b; b = t; } return a;
}
template<typename T> T lcm(T a, T b) { 
    return a / gcd(a, b) * b;
}

int main(int argc, char const *argv[])
{
    while (~scanf("%lld%d", &N, &M)) {
        --N; int k = 0;
        for (int i = 0, x; i < M; ++i) {
            scanf("%d", &x);
            if (x) A[k++] = x;
        }
        ll ans = 0;
        for (int i = 1; i < 1 << k; ++i) {
            int mul = 1, cnt = 0;
            for (int j = 0; j < k; ++j)
                if (i >> j & 1) mul = lcm(mul, A[j]), ++cnt;
            ans += (N / mul) * (cnt & 1? 1 : -1);
        }
        printf("%lld\n", ans);
    }    
    return 0;
}