// written at 16:52 on 05 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";
};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

bool solve(int &w) {
    int w1, w2, d1, d2;
    bool b1 = true, b2 = true;
    scanf("%d%d%d%d", &w1, &d1, &w2, &d2);
    if (!w1) b1 = solve(w1);
    if (!w2) b2 = solve(w2);
    w = w1 + w2;
    return b1 && b2 && ((ll)w1 * d1 == (ll)w2 * d2);
}

int main() {
    int t, w;
    scanf("%d", &t);
    while (t--) {
        puts(solve(w) ? "YES" : "NO");
        if (t) puts("");
    }
    return 0;
}
