// written at 23:57 on 17 Aug 2018
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

const int maxn = 500 + 5;

int n, step[maxn * 2];
string ans;
Pii loc[maxn * 2];

bool query(int r1, int c1, int r2, int c2) {
    cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
    cout.flush();
    cin >> ans;
    return ans == "YES";
}

int main() {
    scanf("%d", &n);
    loc[0] = Pii(1, 1);
    for (int i = 0; i < n - 1; i++) {
        if (query(loc[i].first + 1, loc[i].second, n, n)) {
            loc[i + 1] = Pii(loc[i].first + 1, loc[i].second);
            step[i] = 0;
            continue;
        }
        if (query(loc[i].first, loc[i].second + 1, n, n)) {
            loc[i + 1] = Pii(loc[i].first, loc[i].second + 1);
            step[i] = 1;
            continue;
        }
    }
    loc[2 * n - 2] = Pii(n, n);
    for (int i = 2 * n - 2; i > n; i--) {
        if (query(loc[i - n].first, loc[i - n].second, loc[i].first, loc[i].second - 1)) {
            loc[i - 1] = Pii(loc[i].first, loc[i].second - 1);
            step[i - 1] = 1;
            continue;
        }
        if (query(loc[i - n].first, loc[i - n].second, loc[i].first - 1, loc[i].second)) {
            loc[i - 1] = Pii(loc[i].first - 1, loc[i].second);
            step[i - 1] = 0;
            continue;
        }
    }
    if (loc[n].first == loc[n - 1].first + 1) step[n - 1] = 0; else step[n - 1] = 1;
    cout << "! ";
    for (int i = 0; i < 2 * n - 2; i++) if (step[i] == 0) cout << "D"; else cout << "R";
    cout << endl;
    cout.flush();
    return 0;
}
