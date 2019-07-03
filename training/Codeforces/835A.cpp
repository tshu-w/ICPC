// written at 22:08 on 31 Jul 2017
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

int s, v1, v2, t1, t2;

int main() {
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int cost1 = s * v1 + 2 * t1;
    int cost2 = s * v2 + 2 * t2;
    if (cost1 == cost2) cout << "Friendship\n";
    else if (cost1 < cost2) cout << "First\n";
    else cout << "Second\n";
    return 0;
}
