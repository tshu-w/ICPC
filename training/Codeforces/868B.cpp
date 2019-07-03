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

int h, m, s, t1, t2;
 double p[5];

int main() {
    cin >> h >> m >> s >> t1 >> t2;
    p[0] = (h + (m / 60. + s / 3600.)) * 5;
    p[1] = m + (s / 60.);
    p[2] = s;
    for (int i = 0; i < 3; i++) if (p[i] >= 60) p[i] -= 60;
    sort(p, p + 3);
    p[3] = p[0] + 60;
    t1 = t1 * 5; if (t1 >= 60) t1 -= 60; if (t1 + 60 < p[3]) t1 += 60;
    t2 = t2 * 5; if (t2 >= 60) t2 -= 60; if (t2 + 60 < p[3]) t2 += 60;
    bool flag = false;
    for (int i = 0; i < 3; i++)
        if ((p[i] < t1 && t1 < p[i + 1] && p[i] < t2 && t2 < p[i + 1])) flag = true;
    printf(flag? "YES\n" : "NO\n");
    return 0;
}
