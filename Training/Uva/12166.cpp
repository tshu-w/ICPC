// written at 14:19 on 06 Sep 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

string s;
int t, tot, cnt;
map<ll, int> mp;

void dfs(int d, int l, int r) {
    if (s[l] == '[') {
        int p = 0;
        for (int i = l; i < r; i++) {
            if (s[i] == '[') p++;
            if (s[i] == ']') p--;
            if (p == 1 && s[i] == ',') {
                dfs(d + 1, l + 1, i);
                dfs(d + 1, i + 1, r - 1);
            }
        }
    } else {
        ll num = 0;
        for (int i = l; i < r; i++)
            num = num * 10 + s[i] - '0';
        tot++;
        cnt = max(cnt, ++mp[num << d]);
    }
}

int main() {
    IOS;
    cin >> t;
    while (t--) {
        cin >> s;
        mp.clear();
        tot = cnt = 0;
        dfs(0, 0, s.size());
        cout << tot - cnt << endl;;
    }
    return 0;
}
