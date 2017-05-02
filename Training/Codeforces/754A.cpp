// written at 20:24 on 17 Jan 2017 
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
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e2 + 10;

int N, A[MAX_N], sum, pre;

int main(int argc, char const *argv[])
{
    bool f = false;
    cin >> N;
    rep(i, 0, N) {
        cin >> A[i];
        if (A[i]) f = true;
        sum += A[i];
    }
    if (f) {
        puts("YES");
        if (sum) {
            printf("1\n");
            printf("%d %d\n", 1, N);
        } else {
            rep(i, 0, N - 1) {
                pre += A[i];
                if (pre) {
                    printf("2\n");
                    printf("%d %d\n", 1, i + 1);
                    printf("%d %d\n", i + 2, N);
                    break;
                }
            }
        }
    } else puts("NO");
    return 0;
}