// written at 19:46 on 14 Feb 2018
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

const int maxn = 50 + 10;

int n, m, a[maxn], b[maxn], p;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    ll llmax = LLONG_MIN;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (1ll * a[i] * b[j] > llmax) {
                p = i;
                llmax = 1ll * a[i] * b[j];
            }
    llmax = LLONG_MIN;
    for (int i = 0; i < n; i++)
        if (i != p)
            for (int j = 0; j < m; j++)
                llmax = max(llmax, 1ll * a[i] * b[j]);
    cout << llmax << endl;
    return 0;
}
