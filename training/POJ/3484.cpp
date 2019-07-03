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
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

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

ull X[MAX_N], Y[MAX_N], Z[MAX_N], C[MAX_N];
int N;

char buf[1024];
bool read() {
    bool flag = false;
    N = 0;
    while ((flag = (gets(buf) != NULL)) && strlen(buf) > 2) {
        sscanf(buf, "%lld%lld%lld", X + N, Y + N, Z + N);
        ++N;
    }
    return N || flag;
}

ull count(ull ceil) {
    ull sum = 0;
    for (int i = 0; i < N; ++i)
        if (ceil >= Y[i])
            sum += C[i];
        else if (ceil >= X[i]) sum += (ceil - X[i]) / Z[i] + 1;
    return sum;
}

int main(int argc, char const *argv[])
{
    while (read()) {
        if (!N) continue;
        ull lower_bit = 0;
        for (int i = 0; i < N; ++i) {
            C[i] = (Y[i] - X[i]) / Z[i] + 1;
            lower_bit ^= C[i];
        }    
        if (!(lower_bit & 1)) {
            printf("no corruption\n");
        } else {
            ull lb = 0, ub = INF;
            while (ub - lb > 1) {
                ull mid = (ub - lb) / 2 + lb;
                if (count(mid) & 1) ub = mid;
                else lb = mid;
            }
            printf("%lld %lld\n", ub, count(ub) - count(ub - 1));
        }
    }
    return 0;
}