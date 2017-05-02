#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 100 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, A[MAX_N], B[MAX_N], C[MAX_N];

bool satisfy(int n, int it) {
    int num[10], b, c, m = n, ait = A[it];
    b = c = 0;
    memset(num, 0, sizeof num);
    for (int i = 0; i < 4; ++i) {
        if (ait% 10 == n % 10) ++c;
        num[ait % 10]++;
        ait /= 10; n /= 10;
    }
    if (c != C[it]) return false;
    for (int i = 0; i < 4; ++i) {
        if (num[m % 10]) {
            ++b; num[m % 10]--;
        }
        m /= 10;
    }
    if (b != B[it]) return false;
    return true;
}

void solve() {
    int ans = 0;
    for (int i = 1000; i <= 9999; ++i) {
        bool flag = true;
        for (int j = 0; j < N; ++j) {
            if (!satisfy(i, j))
                flag = false;
        }
        if (flag) {
            if (ans) {
                printf("Not sure\n");
                return;
            }
            else ans = i;
        }
    }
    if (ans)
        printf("%d\n", ans);
    else
        printf("Not sure\n");
}

int main(int argc, char const *argv[])
{
    while (~scanf("%d", &N) && N) {
        for (int i = 0; i < N; ++i)
            scanf("%d%d%d", A + i, B + i, C + i);
        solve();
    }    
    return 0;
}