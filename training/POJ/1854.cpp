// written at 10:44 on 11 Mar 2017 
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
const int MAX_N = 1e4 + 10;

int t;
char s[MAX_N];

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int len = strlen(s), cnt[26] = {0}, odd = 0;
        for (int i = 0; i < len; i++)
            cnt[s[i] - 'a']++;
        for (int i = 0; i < 26; i++)
            if (cnt[i] & 1) odd++;
        if (odd > 1) 
            puts("Impossible");
        else {
            int ans = 0;
            for (int i = 0, j = len - 1; i < j; i++, j--) {
                int l = i, r = j;
                while (l < j && s[l] != s[j]) l++;
                while (i < r && s[i] != s[r]) r--;
                if (l - i < j - r) {
                    for (int k = l; k > i; k--) {
                        swap(s[k], s[k - 1]);
                        ++ans;
                    }
                } else {
                    for (int k = r; k < j; k++) {
                        swap(s[k], s[k + 1]);
                        ++ans;
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}