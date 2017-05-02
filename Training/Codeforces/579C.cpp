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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    if (a < b)
        printf("%.12f\n", -1.);
    else
        if (a == b)
            printf("%.12f\n", (double)a);
        else 
            printf("%.12f\n", min( (a - b) / (2. * ((a - b) / (2 * b))) , (a + b) / (2. * ( (a + b) / (2 * b) ) ) ) ); 
    return 0;
}