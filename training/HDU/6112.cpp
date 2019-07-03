// written at 14:01 on 12 Aug 2017
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

int t, y, m, d;

bool is_leap(int y) {
    return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}

bool is_pre(int m, int d) {
    return (m < 2 || (m == 2 && d < 29));
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d-%d-%d", &y, &m, &d);
        if (m == 2 && d == 29) {
            int cnt = 0;
            for (int i = y; i <= i + 100; i += 4) {
                if (is_leap(i + 4)) {
                    cnt += 365 * 3 + 366;
                    cnt %= 7;
                    if (cnt == 0) {
                        printf("%d\n", i + 4);
                        break;
                    }
                } else {
                    cnt += 365 * 4;
                    cnt %= 7;
                }
            }
        } else {
            bool pre = is_pre(m, d);
            int cnt = 0;
            for (int i = y; i <= y + 100; i++) {
                cnt += 365;
                if (is_leap(i)) {
                    if (pre) cnt++;
                } else if (is_leap(i + 1)) {
                    if (!pre) cnt++;
                }
                cnt %= 7;
                if (cnt == 0) {
                    printf("%d\n", i + 1);
                    break;
                }
            }
        }
    }
    return 0;
}
