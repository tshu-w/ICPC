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
const int MAX_N = 100 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, C, used[MAX_N], ans = 0;
Pii A[MAX_N];

int main(int argc, char const *argv[])
{
    cin >> N >> C;
    for (int i = 0; i < N; ++i)
        cin >> A[i].first >> A[i].second;
    sort(A, A + N);
    while (true) {
        int sum = C;
        memset(used, 0, sizeof used);
        for (int i = N - 1; i >= 0; --i) 
            if (sum > 0 && A[i].second > 0) {
                int tmp = min(A[i].second, sum / A[i].first);
                if (tmp > 0) {
                    sum -= tmp * A[i].first;
                    used[i] += tmp;
                }
            }
        for (int i = 0; i < N; ++i)
            if (sum > 0 && A[i].second > 0 && A[i].first >= sum) {
                sum -= A[i].first;
                ++used[i];
                break;
            }
        if (sum > 0) break;
        int tmp = INF;
        for (int i = 0; i < N; ++i)
            if (used[i]) tmp = min(tmp, A[i].second / used[i]);
        ans += tmp;
        for (int i = 0; i < N; ++i)
            if (used[i]) A[i].second -= tmp * used[i];
    }
    cout << ans << endl;
    return 0;
}