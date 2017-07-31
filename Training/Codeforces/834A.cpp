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


string s = "v<^>";
int n, l, r;
char fir, lst;

int main() {
    cin >> fir >> lst;
    cin >> n;
    for (int i = 0; i < (int)s.size(); i++) {
        if (fir == s[i]) l = i;
        if (lst == s[i]) r = i;
    }
    if (s[(l + n % 4) % 4] == s[r] && s[(r + n % 4) % 4] != s[l]) cout << "cw" << endl;
    else if (s[(l + n % 4) % 4] != s[r] && s[(r + n % 4) % 4] == s[l]) cout << "ccw" << endl;
    else cout << "undefined" << endl;
    cerr << "test" << endl;
    return 0;
}
