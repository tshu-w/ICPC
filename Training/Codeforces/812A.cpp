// written at 21:25 on 01 Jun 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 1e5 + 10;

int main(void) {
    int a[10][10];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> a[i][j];
    bool flag = false;
    for (int i = 0; i < 4; i++) if (a[i][3] == 1) {
        for (int j = 0; j < 3; j++)
            if (a[i][j] == 1) flag = true;
    }
    for (int i = 0; i < 4; i++) {
        int j = (i + 2) % 4;
        if (a[i][1] == 1 && a[j][3] == 1) flag = true;
        j = (i + 1) % 4;
        if (a[i][2] == 1 && a[j][3] == 1) flag = true;
        j = (i - 1 + 4) % 4;
        if (a[i][0] == 1 && a[j][3] == 1) flag = true;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
