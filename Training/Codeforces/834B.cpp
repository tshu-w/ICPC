// written at 22:19 on 30 Jul 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

int n, k, l[30], r[30];
string s;

int main() {
    cin >> n >> k;
    cin >> s;
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    for (int i = 0; i < (int)s.size(); i++)
        if (l[s[i] - 'A'] == -1) l[s[i] - 'A'] = i;
    for (int i = (int)s.size() - 1; i >= 0; i--)
        if (r[s[i] - 'A'] == -1) r[s[i] - 'A'] = i;
    int cnt = 0;
    bool flag = true;
    for (int i = 0; i < (int)s.size(); i++) {
        if (l[s[i] - 'A'] == i) cnt++;
        if (cnt > k) flag = false;
        if (r[s[i] - 'A'] == i) cnt--;
    }
    if (flag) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
