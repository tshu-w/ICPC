// written at 22:34 on 17 Aug 2018
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

int n, m;
string s, t;

int main() {
    cin >> n >> m >> s >> t;
    int pos = -1;
    for (int i = 0; i < n; i++) if (s[i] == '*') { pos = i; break;}
    if (pos == -1) puts(s == t? "YES" : "NO");
    else {
        bool flag = n - 1 <= m;
        for (int i = 0; i < pos && flag; i++) if (s[i] != t[i]) flag = false;
        for (int i = n - 1; i > pos && flag; i--) if (s[i] != t[i - n + m]) flag = false;
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
