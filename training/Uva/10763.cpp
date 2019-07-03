// written at 19:35 on 09 May 2017
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

const int MAX_N = 500000 + 10;

int main(void) {
    int n, org[MAX_N], trg[MAX_N];
    while (scanf("%d", &n) && n) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", org + i, trg + i);
        }
        sort(org, org + n);
        sort(trg, trg + n);
        for (int i = 0; i < n && flag; i++)
            flag = org[i] == trg[i];
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
