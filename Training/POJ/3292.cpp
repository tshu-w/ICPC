#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <bitset>

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
const int MAX_N = 1e6 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, sum[MAX_N], isHPrime[MAX_N];

void seive(int n) {
    memset(isHPrime, 0, sizeof isHPrime);
    for (int i = 5; i < MAX_N; i += 4)
        for (int j = 5; j <= i; j += 4)
            if ((ll)i * j < (ll)MAX_N) {
                if (isHPrime[i] == 0 && isHPrime[j] == 0)
                    isHPrime[i * j] = 1;
                else isHPrime[i * j] = 2;
            }
            else break;
}

int main(int argc, char const *argv[])
{
    seive(1e6);
    for (int i = 1; i < MAX_N; ++i) {
        sum[i + 1] = sum[i] + ((isHPrime[i] == 1)? 1 : 0);
        // if (!isHPrime[i]) cout << i << endl;
    }
    while (scanf("%d", &n) && n) {
        printf("%d %d\n", n, sum[n + 1]);
    }
    return 0;
}
