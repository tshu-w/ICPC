// written at 23:08 on 18 Mar 2017
#include <bits/stdc++.h>

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

int n, k, cnt;
bool flag[MAX_N];
string ans[MAX_N];

inline string nm(int cnt) {
    string res;
    if (cnt < 26) res = "A";
    else res = "B";
    char ch = cnt % 26 + 'a';
    res += ch;
    return res;
}
int main() {
    cin >> n >> k;
    for (int i = 0; i < n - k + 1; i++) {
        string s;
        cin >> s;
        flag[i] = s == "YES";
    }
    if (!flag[0]) {
        ans[0] = nm(cnt);
        for (int i = 1; i < k; i++)
            ans[i] = nm(cnt++);
    } else {
        for (int i = 0; i < k; i++)
            ans[i] = nm(cnt++);
    }
    // for (int i = 0; i < k; i++)
    //     cout << ans[i] << endl;
    for (int i = k; i < n; i++) {
        if (flag[i - k + 1]) {
            ans[i] = nm(cnt++);
        } else {
            ans[i] = ans[i - k + 1];
        }
        // if (!flag[i - k] && flag[i - k + 1])

        // if (!flag[i - k] && !flag[i - k + 1])

        // if (flag[i - k] && flag[i - k + 1])

        // if (flag[i - k] && !flag[i - k + 1])
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}