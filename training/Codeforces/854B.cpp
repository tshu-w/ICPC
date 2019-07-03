// written at 20:38 on 06 Sep 2017
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

int n, k;

int main() {
    while (cin >> n >> k) {
        if (n == k || k == 0) {
            cout << "0 0" << endl;
        } else {
            cout << 1 << " ";
            if (k < (n + 2) / 3) cout << min(2 * k, n - k) << endl;
            else cout << n - k << endl;
        }
    }
    return 0;
}
