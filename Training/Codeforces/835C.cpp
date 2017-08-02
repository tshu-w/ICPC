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

const int MAX_M = 100 + 10;
const int MAX_C = 15;

int n, q, c;
int cnt[MAX_M][MAX_M][MAX_C];

int main() {
    scanf("%d%d%d", &n, &q, &c);
    for (int i = 0; i < n; i++) {
        int x, y, s;
        scanf("%d%d%d", &x, &y, &s);
        cnt[x][y][s]++;
    }

    for (int i = 0; i <= c; i++) {
        for (int x = 1; x <= 100; x++)
            for (int y = 1; y <= 100; y++)
                cnt[x][y][i] += cnt[x - 1][y][i] + cnt[x][y - 1][i] - cnt[x - 1][y - 1][i];
    }

    for (int i = 0; i < q; i++) {
        int t, x1, x2, y1, y2;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2); --x1, --y1;
        int ans = 0;
        for (int j = 0; j <= c; j++) {
            // cout <<j << " " << cnt[x2][y2][j] - cnt[x2][y1][j] - cnt[x1][y2][j] + cnt[x1][y1][j] << endl;
            ans += (cnt[x2][y2][j] - cnt[x2][y1][j] - cnt[x1][y2][j] + cnt[x1][y1][j]) * ((t + j) % (c + 1));
        }
        printf("%d\n", ans);
    }
    return 0;
}
