// written at 09:27 on 09 Mar 2018
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

int a, b;

int main() {
    cin >> a >> b;
    int lb = max(a * 2, b * 3) - 1, ub = 6e6;
    while (lb + 1 < ub) {
        int mid = (lb + ub) / 2;
        if (mid / 2 >= a && mid / 3 >= b && mid / 2 + mid / 3 - mid / 6 >= a + b) ub = mid;
        else lb = mid;
    }
    cout << ub << endl;
    return 0;
}
