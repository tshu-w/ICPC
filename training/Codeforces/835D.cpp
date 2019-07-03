// written at 22:08 on 31 Jul 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";
};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 5000 + 10;
const ull t = 107;

string s, rs;
int cnt[MAX_N], n, dp[MAX_N][MAX_N];
ull hs[MAX_N], rhs[MAX_N], pw[MAX_N];

int main() {
    cin >> s;
    n = s.size();
    pw[0] = 1; for (int i = 1; i < n; i++) pw[i] = pw[i - 1] * t;
    for (int i = 0; i < n; i++) hs[i + 1] = hs[i] * t + s[i];
    rs = s; reverse(rs.begin(), rs.end());
    for (int i = 0; i < n; i++) rhs[i + 1] = rhs[i] * t + rs[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            string ss = s.substr(i, j - i);
            int mid = (i + j) / 2;
            if (hs[j] - hs[i] * pw[j - i] == rhs[n - i] - rhs[n - j] * pw[j - i]) {
                dp[i][j] = 1 + dp[i][mid];
                cnt[dp[i][j]]++;
                // cout << ss << " " << i << " " << j << ": " << dp[i][j] << endl;
            } else dp[i][j] = 0;
        }
    }
    for (int i = n - 1; i >= 1; i--)
        cnt[i] += cnt[i + 1];
    for (int i = 1; i <= n; i++)
        printf("%d ", cnt[i]);
    printf("\n");
    return 0;
}
