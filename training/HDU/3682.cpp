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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, M, t, a, b, cnt;
char ch1, ch2;
pair<Pii, int> v[MAX_N * MAX_N];

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d\n", &N, &M);
        cnt = 0;
        for (int i = 0; i < M; ++i) {
            scanf("%c=%d,%c=%d\n", &ch1, &a, &ch2, &b);
            if (ch1 > ch2) {
                swap(ch1, ch2);
                swap(a, b);
            }
            for (int j = 1; j <= N; ++j) {
                if (ch1 == 'X' && ch2 == 'Y') v[cnt++] = make_pair(Pii(a, b), j);
                if (ch1 == 'X' && ch2 == 'Z') v[cnt++] = make_pair(Pii(a, j), b);
                if (ch1 == 'Y' && ch2 == 'Z') v[cnt++] = make_pair(Pii(j, a), b);
            }
        }
        sort(v, v + cnt);
        int ans = unique(v, v + cnt) - v;
        printf("%d\n", ans);
    }    
    return 0;
}