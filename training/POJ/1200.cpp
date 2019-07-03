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

int N, NC, len, hsh[16000000 + 10], c[300];
char s[MAX_N];

int main(int argc, char const *argv[])
{
    while (~scanf("%d%d", &N, &NC)) {
        scanf("%s", s);
        memset(c, 0, sizeof c);
        memset(hsh, 0, sizeof hsh);
        len = strlen(s);
        for (int i = 0, j = 0; i < len; ++i)
            if (!c[s[i]]) c[s[i]] = j++;

        int t = 1, hs = 0, cnt = 0;
        for (int i = 0; i < N; ++i) t *= NC;

        for (int i = 0; i < N; ++i) hs = hs * NC + c[s[i]];
        for (int i = 0; i + N <= len; ++i) {
            if (!hsh[hs]) {
                hsh[hs] = 1;
                ++cnt;
            }
            if (i + N < len) hs = hs * NC + c[s[i + N]] - c[s[i]] * t;
        }
        printf("%d\n", cnt);
    }
    return 0;
}