// written at 22:00 on 23 Dec 2017
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

int v1, v2, v3, v4, a1, a2, a3;

int main() {
    cin >> v1 >> v2 >> v3 >> v4;
    bool flag = false;
    for (int i = v1; i <= 2 * v1 && !flag; i++)
        for (int j = v2; j <= 2 * v2 && !flag; j++)
            if (j < i)
            for (int k = v3; k <= 2 * v3 && !flag; k++)
                if (k < j)
                    if (v4 <= k && 2 * v4 >= k && 2 * v4 < j) {
                        flag = true;
                        a1 = i; a2 = j; a3 = k;
                    }
    if (flag) {
        cout << a1 << endl;
        cout << a2 << endl;
        cout << a3 << endl;
    } else cout << -1 << endl;
    return 0;
}
