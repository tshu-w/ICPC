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

const int maxn = 20;

char ch[maxn][maxn];
int x, y;

int main() {
    for (int i = 0; i < 11; i++) gets(ch[i]);
    scanf("%d%d", &x, &y); x--; y--;
    x = x - x / 3 * 3;
    y = y - y / 3 * 3;
    bool flag = false;
    for (int i = x * 4; i < x * 4 + 3; i++)
        for (int j = y * 4; j < y * 4 + 3; j++)
            if (ch[i][j] == '.') flag = true;
    if (flag) {
        for (int i = x * 4; i < x * 4 + 3; i++)
            for (int j = y * 4; j < y * 4 + 3; j++)
                if (ch[i][j] == '.') ch[i][j] = '!';
    } else {
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 11; j++)
                if (ch[i][j] == '.') ch[i][j] = '!';
    }
    for (int i = 0; i < 11; i++) puts(ch[i]);
    return 0;
}
