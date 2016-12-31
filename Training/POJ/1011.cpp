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

int N, A[MAX_N], sum, len;
bool flag[MAX_N];

bool dfs(int i, int res, int tot) {
    if (res == 0) {
        if (tot - len == 0) return true;
        if (dfs(0, len, tot - len)) return true;
    } else {
        if (i == 0) {
            for (;flag[i]; ++i);
            flag[i] = true;
            if (dfs(i + 1, len - A[i], tot)) return true;
            flag[i] = false;
        } else {
            for (int j = i; j < N; ++j) {
                if (j && A[j] == A[j - 1] && !flag[j - 1]) continue;
                if (!flag[j] && res >= A[j]) {
                    flag[j] = true;
                    if (dfs(j, res - A[j], tot)) return true;
                    flag[j] = false;
                    if (res == A[j])
                        break;
                }
            }
        }
    }
    return false;
}
bool cmp(const int a, const int b) {
    return a > b;
}
int main(int argc, char const *argv[])
{
    while (~scanf("%d", &N) && N) {
        sum = 0;
        for (int i = 0; i < N; ++i)
            scanf("%d", A + i), sum += A[i];
        
        sort(A, A + N, cmp);
        memset(flag, false, sizeof flag);
        bool success = false;
        for (len = A[0]; len <= sum / 2; ++len) {
            if (sum % len == 0 && dfs(0, len, sum)) {
                printf("%d\n", len);
                success = true;
                break;
            }
        }
        if (!success)
            printf("%d\n", sum);
    }
    return 0;
}