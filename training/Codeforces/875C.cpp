// written at 18:55 on 16 Oct 2017
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

int n;
vector<int> v;

int sum(int m) {
    int res = 0;
    while (m) {
        res += m % 10;
        m /= 10;
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = max(n - 10000, 0); i <= n; i++) {
        if (n == i + sum(i)) v.push_back(i);
    }
    printf("%d\n", (int)v.size());
    if (v.size() != 0) {
        for (auto x : v) printf("%d ", x);
        printf("\n");
    }
    return 0;
}
