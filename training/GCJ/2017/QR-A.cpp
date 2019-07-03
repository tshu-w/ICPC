// written at 16:53 on 8 Apr 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif
#define filename "A-large"
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

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e3 + 10;

int t, n, dir[MAX_N], f[MAX_N], k;
string s;

int cal(int k) {
    memset(f, 0, sizeof f);
    int sum = 0, res = 0;

    for (int i = 0; i + k <= n; ++i) {
        if ((dir[i] + sum) % 2 != 0) {
            ++res;
            f[i] = 1;
        }
        sum += f[i];
        if (i - k + 1 >= 0) 
            sum -= f[i - k + 1];
    }    

    for (int i = n - k + 1; i < n; ++i) {
        if ((dir[i] + sum) % 2 != 0) {
            return -1;
        }
        if (i - k + 1 >= 0) 
            sum -= f[i - k + 1];
    }

    return res;
}

int main() {
    setfile();
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> s >> k;
        n = s.length();
        for (int i = 0; i < n; i++)
            if (s[i] == '-') dir[i] = 1;
            else dir[i] = 0;
        printf("Case #%d: ", _ + 1);
        int ans = cal(k);
        if (ans == -1) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
    }
    resetfile();
}