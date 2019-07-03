// written at 14:54 on 05 Oct 2017
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

string s, ss;
int n;

int main() {
    cin >> s;
    cin >> n;
    bool flag1 = false, flag2 = false, flag3 = false;
    for (int i = 0; i < n; i++) {
        cin >> ss;
        if (ss == s) flag3 = true;
        if (ss[1] == s[0]) flag1 = true;
        if (ss[0] == s[1]) flag2 = true;
    }
    if ((flag1 && flag2) || flag3) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
