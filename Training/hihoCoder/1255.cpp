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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e6 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, A[10][2], B[20];

int f(int n) {
    if (n == 0) return 1;
    else return 0;
}

bool check(int i, int j, int k) {
    for (int a = 0; a < 2; ++a)
        for (int b = 0; b < 2; ++b)
            for (int c = 0; c < 2; ++c) {
                    if (A[i][a] == A[j][b] && A[i][a] == A[k][c]) return 1;
                    if (A[i][a] == A[j][b] + A[k][c] && A[j][1 ^ b] == A[k][1 ^ c]) return 1;
                }
    return false;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 4; ++i) {
            scanf("%d%d", &A[i][0], &A[i][1]);
            B[i] = i;
        }
        int flag = false;
        do {
            if (check(B[0], B[1], B[2])) flag = true;
        } while (next_permutation(B, B + 4));
        if (flag)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}