// written at 17:37 on 6 Mar 2017 
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
#include <numeric>

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
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e2 + 10;

int N, A[MAX_N], sum, max_len;
bool flag[MAX_N];

bool dfs(int k, int rem, int len, int last) {
    // cout << k << " " << rem << " " << len << " " << last << endl;
    if (rem == 0) k--, rem = len, last = max_len + 1;
    if (k == 0) {
        printf("%d\n", len);
        return true;
    }
    for (int i = 0; i < N; i++)
        if (!flag[i] && A[i] < last) {
            if (A[i] > rem) continue;
            flag[i] = true;
            if (dfs(k, rem - A[i], len, A[i] + 1)) return true;
            flag[i] = false;
            last = A[i];
        }
    return false;
}

int main(int argc, char const *argv[])
{
    while (scanf("%d", &N), N) {
        max_len = 0;
        sum = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", A + i);
            sum += A[i];
            max_len = max(max_len, A[i]);
        }
        sort(A, A + N, greater<int>());
        for (int i = max_len; i <= sum; i++) 
            if (sum % i == 0) {
                memset(flag, false, sizeof flag);
                if (dfs(sum / i, i, i, max_len + 1))
                    break;
            }
    }
    return 0;
}