// written at 20:36 on 17 Mar 2017
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
const int MAX_N = 1e5 + 10;
const ull B = 100000007;

string s[3];
ull hsh[3][MAX_N], bp[MAX_N];

void init_hash() {
    int n = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < s[i].size(); j++) {
            hsh[i][j + 1] = hsh[i][j] * B + s[i][j];
            // printf("%llu%c", hsh[i][j + 1], " \n"[j + 1 == s[i].size()]);
        }
        n = max(n, (int)s[i].size());
    }
    bp[0] = 1;
    for (int i = 1; i <= n; i++) bp[i] = bp[i - 1] * B;
    // for (int i = 1; i <= n; i++) printf("%llu ", bp[i]);
}

inline ull cal_hash(ull *hs, int l, int r) {
    return hs[r] - hs[l] * bp[r - l];
}

bool contain(int a, int b) {
    if (s[a].size() < s[b].size()) return false;
    ull res = hsh[b][s[b].size()];
    for (int i = 0; i + s[b].size() <= s[a].size(); i++)
        if (cal_hash(hsh[a], i, i + s[b].size()) == res) return true;
    return false;
}

int overlap(int a, int b) {
    int res = 0;
    for (int i = 1; i <= min(s[a].size(), s[b].size()); i++)
        if (cal_hash(hsh[a], s[a].size() - i, s[a].size()) == cal_hash(hsh[b], 0, i)) res = i;
    return res;
}

int solve() {
    int ans = MAX_N * 3;
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++) if (contain(i, j) || contain(j, i)) {
            int x = s[i].size() >= s[j].size()? i : j, y = 3 - i - j;
            if (contain(x, y) || contain(y, x)) return max(s[x].size(), s[y].size());
            else return s[x].size() + s[y].size() - max(overlap(x, y), overlap(y, x));
        }
    int sum = 0;
    for (int i = 0; i < 3; i++) sum += s[i].size();
    int id[] = {0, 1, 2};
    do {
        ans = min(ans, sum - overlap(id[0], id[1]) - overlap(id[1], id[2]));
    }
    while (next_permutation(id, id + 3));
    return ans;
}

int main() {
    for (int i = 0; i < 3; i++)
        cin >> s[i];
    init_hash();
    printf("%d", solve());
    return 0;
}
