// written at 19:47 on 14 Feb 2018
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

ll p, k;
vector<ll> v;

int main() {
    cin >> p >> k;
    while (p) {
        if (p % (-k) < 0) {
            v.push_back(p % (-k) + k);
            p = p / (-k) + 1;
        } else {
            v.push_back(p % (-k));
            p /= (-k);
        }
    }
    cout << v.size() << endl;
    for (int i = 0; i <= SZ(v); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
