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
const int MAX_N = 1000;
const double eps = 1e-6;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, d, cs = 0;
pair<double, double> A[MAX_N];
double x, y;

int main(int argc, char const *argv[])
{
    while(~scanf("%d%d", &N, &d) && (N || d)) {
        bool flag = d < 0.? false : true;
        for (int i = 0; i < N; ++i) {
            scanf("%lf%lf", &x, &y);
            if (y > d) {flag = false; continue;}
            A[i].first = x + sqrt(sqr(d) - sqr(y));
            A[i].second = x - sqrt(sqr(d) - sqr(y));
        }
        sort(A, A + N);
        int i = 0, ans = 0;
        while (i < N) {
            pair<double, double> s = A[i++];
            while (i < N && A[i].second <= s.first) ++i;
            ++ans;
        }
        printf("Case %d: %d\n", ++cs, i == N && flag? ans : -1);
    }
    return 0;
}