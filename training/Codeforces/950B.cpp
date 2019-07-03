// written at 15:59 on 09 Mar 2018
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

const int maxn = 1e5 + 10;

int n, m, x[maxn], y[maxn], ans;
ll sumx, sumy;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", x + i);
    for (int j = 0; j < m; j++) scanf("%d", y + j);
    int l = 0, r = 0;
    sumx += x[l++], sumy += y[r++];
    while (l < n && r < m) {
        if (sumx == sumy) {
            ans++;
            sumx = x[l++];
            sumy = y[r++];
        }
        else if (sumx < sumy) sumx += x[l++];
        else sumy += y[r++];
    }
    cout << ans + 1<< endl;
    return 0;
}
