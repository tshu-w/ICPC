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
const int MAX_N = 100000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, A[MAX_N], B[MAX_N], cnt[MAX_N], pos[MAX_N];

void merge_sort(int l, int r) {
    if (l >= r) return ;
    int mid = (r - l) / 2 + l;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    int i, j, k;
    i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (A[i] > A[j]) {
            B[k] = A[i];
            cnt[A[i]] += r - j + 1;
            ++i;
        } else {
            B[k] = A[j];
            ++j;
        }
        ++k;
    }
    while (i <= mid) {
        B[k] = A[i++];
        ++k;
    }
    while (j <= r) {
        B[k] = A[j++];
        ++k;
    }
    for (int i = l; i <= r; ++i)
        A[i] = B[i];
    return ;
}

int main(int argc, char const *argv[]) {
    int t, cases = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            scanf("%d", A + i);
            pos[A[i]] = i;
        }
        memset(cnt, 0, sizeof cnt);
        memset(B, 0, sizeof B);

        merge_sort(1, N);
        printf("Case #%d: ", ++cases);
        for (int i = 1; i <= N; ++i)
            printf("%d%c", pos[i] + cnt[i] - min(i, pos[i]), (i == N)? '\n' : ' ');
    }
    return 0;
}