// written at 09:09 on 26 Apr 2017
// 01:08 small
//
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename "B-large-practice"
#define setfile() freopen(filename".in.txt", "r", stdin); freopen(filename".ans.txt", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans.txt");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const char mp[] = "ROYGBV";

int t, n, A[10]; // R O Y G B V

bool check(int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0) return false;
    if (A[0] == A[3] &&  A[0] != 0 && (b || c)) return false;
    if (A[2] == A[5] && A[2] != 0 && (a || c)) return false;
    if (A[4] == A[1] && A[4] != 0 && (a || b)) return false;
    if (a >= b && a >= c) return a <= b + c;
    if (b >= a && b >= c) return b <= a + c;
    if (c >= a && c >= b) return c <= a + b;
    return false;
}

void generate(int a, int b, int c, int d, int e, int f) {
    while (A[a]) {
        while (A[a] && A[d]) {
            putchar(mp[a]); --A[a];
            putchar(mp[d]); --A[d];
        }
        if (A[a]) {putchar(mp[a]); --A[a];}
        if (A[b] - A[e] >= A[c] - A[f]) {
            while (A[b] && A[e]) {
                putchar(mp[b]); --A[b];
                putchar(mp[e]); --A[e];
            }
            if (A[b]) {putchar(mp[b]); --A[b];}
        } else {
            while (A[c] > 1 && A[f]) {
                putchar(mp[c]); --A[c];
                putchar(mp[f]); --A[f];
            }
            if (A[c]) {putchar(mp[c]); --A[c];}
        }
    }
    while (A[b] || A[c]) {
        if (A[b] - A[e] >= A[c] - A[f]) {
            while (A[b] && A[e]) {
                putchar(mp[b]); --A[b];
                putchar(mp[e]); --A[e];
            }
            if (A[b]) {putchar(mp[b]); --A[b];}
        } else {
            while (A[c] && A[f]) {
                putchar(mp[c]); --A[c];
                putchar(mp[f]); --A[f];
            }
            if (A[c]) {putchar(mp[c]); --A[c];}
        }
    }
    if (A[d]) {
        putchar(mp[d]); --A[d];
    }
    if (A[e]) {
        putchar(mp[e]); --A[e];
    }
    if (A[f]) {
        putchar(mp[f]); --A[f];
    }
    puts("");
}

void solve(int a, int b, int c) {
    if (a >= b && a >= c) {
        generate(0, 2, 4, 3, 5, 1);
        return ;
    }
    if (b >= a && b >= c) {
        generate(2, 0, 4, 5, 3, 1);
        return ;
    }
    if (c >= a && c >= b) {
        generate(4, 0, 2, 1, 3, 5);
        return ;
    }
}

int main(void)
{
    setfile();
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> n;
        for (int i = 0; i < 6; i++)
            cin >> A[i];
        printf("Case #%d: ", _ + 1);
        if (check(A[0] - A[3], A[2] - A[5], A[4] - A[1])) {
            solve(A[0] - A[3], A[2] - A[5], A[4] - A[1]);
        } else puts("IMPOSSIBLE");
    }
    resetfile();
    return 0;
}
