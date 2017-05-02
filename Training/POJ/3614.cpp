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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int C, L;
vector<Pii> cow, bottle;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &C, &L);
    int a, b;
    for (int i = 0; i < C; ++i) {
        scanf("%d%d", &a, &b);
        cow.push_back(Pii(b, a));
    }
    for (int i = 0; i < L; ++i) {
        scanf("%d%d", &a, &b);
        bottle.push_back(Pii(a, b));
    }
    sort(cow.begin(), cow.end());
    sort(bottle.begin(), bottle.end());
    int ans = 0;
    for (int i = 0; i < C; ++i)
        for (int j = 0; j < L; ++j)
            if (bottle[j].second && cow[i].first >= bottle[j].first && cow[i].second <= bottle[j].first) {
                bottle[j].second--;
                ++ans;
                break;
            }
    printf("%d\n", ans);
    return 0;
}