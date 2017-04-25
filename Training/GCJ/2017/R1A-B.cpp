// written at 19:01 on 25 Apr 2017
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
#define filename "B-large-practice"
#define setfile() freopen(filename".in.txt", "r", stdin); freopen(filename".ans.txt", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans.txt");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 50 + 5;

int t, n, q, R[MAX_N], a;
multiset<int> Q[MAX_N];

int main(void) {
    setfile();
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> n >> q;

        int ans = 0;
        for (int i = 0; i < n; i++)
            cin >> R[i];
        for (int i = 0; i < n; i++) {
            Q[i].clear();
            for (int j = 0; j < q; j++) {
                cin >> a;
                Q[i].insert(a);
            }
        }
        int k = 1;
        while (true) {
            bool flag = true, end = false;
            for (int i = 0; i < n; i++) {
                int s = ceil(k * R[i] * 0.9), t = floor(k * R[i] * 1.1);
                auto it = Q[i].lower_bound(s);
                if (it == Q[i].end()) {
                    end = true;
                    break;
                }
                if (*it > t) {
                    flag = false;
                    k++;
                    break;
                }
            }
            if (end) break;
            if (flag) {
                for (int i = 0; i < n; i++) {
                    int s = ceil(k * R[i] * 0.9), t = floor(k * R[i] * 1.1);
                    auto it = Q[i].lower_bound(s);
                    Q[i].erase(it);
                }
                ans++;
            }
        }
        printf("Case #%d: %d\n", _ + 1, ans);
    }
    resetfile();
    return 0;
}
