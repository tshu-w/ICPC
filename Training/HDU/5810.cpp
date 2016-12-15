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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

ll n, m;

ll gcd( ll a, ll b ) {
    if( b == 0 ) return a;
    return gcd( b, a % b );
}

int main() {
    while( ~scanf( "%I64d%I64d", &n, &m ) && n + m ) {
        ll ta = n * ( m - 1 );
        ll tb = m * m;
        if( ta == 0 ) { puts( "0/1" ); continue; }
        ll tt = gcd( ta, tb );
        ta /= tt; tb /= tt;
        printf( "%I64d/%I64d\n", ta, tb );
    }
    return 0;
}