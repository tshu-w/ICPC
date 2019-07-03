// written at 19:14 on 09 May 2017
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

const int MAX_N = 50;

int main(void) {
    int n;
    while (cin >> n && n) {
        vector<int> v(n);
        int front = 0;
        for (int i = 0; i < n; i++) v[i] = i + 1;
        cout << "Discarded cards:";
        if (n == 1) puts("");
        else printf(" ");
        for (int i = 1; i < n; i++) {
            printf("%d", v[front++]);
            v.push_back(v[front++]);
            printf(i + 1 == n? "\n" : ", ");
        }
        printf("Remaining card: %d\n", v[front]);
    }
    return 0;
}
