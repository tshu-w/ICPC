// written at 14:57 on 24 Jan 2018
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <bitset>
#include <numeric>
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 1 << 17;

struct Node {int l, r, data; };

int N; Node Tr[20 * maxn];
int root[maxn], cnt = 0;

int init(int l, int r) {
    int k = cnt++;
    Tr[k].data = 0;
    if (l + 1 < r) {
        Tr[k].l = init(l, (l + r) / 2);
        Tr[k].r = init((l + r) / 2, r);
    }
    return k;
}

void update(int &x, int y, int p, int l, int r) {
    x = cnt++;
    Tr[x] = Tr[y];
    Tr[x].data++;
    if (l + 1 == r) return ;
    if (p < (l + r) / 2) update(Tr[x].l, Tr[y].l, p, l, (l + r) / 2);
    else update(Tr[x].r, Tr[y].r, p, (l + r) / 2, r);
}

int query(int x, int y, int k, int l, int r) {
    if (l + 1 == r) return l;
    int res = Tr[Tr[y].l].data - Tr[Tr[x].l].data;
    if (res >= k) return query(Tr[x].l, Tr[y].l, k, l, (l + r) / 2);
    else return query(Tr[x].r, Tr[y].r, k - res, (l + r) / 2, r);
}

int n, m, A[maxn], B[maxn];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", A + i), B[i] = A[i];

    sort(B, B + n);
    N = 1;
    for (int i = 0; i < n; i++) if (B[i] != B[N - 1]) B[N++] = B[i];

    init(0, N);
    for (int i = 0; i < n; i++) {
        int id = lower_bound(B, B + N, A[i]) - B;
        update(root[i + 1], root[i], id, 0, N);
    }

    for (int i = 0, l, r, k; i < m; i++) {
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", B[query(root[l - 1], root[r], k, 0, N)]);
    }
    return 0;
}

// const int MAX_N = 1e5 + 10;
// const int ST_SIZE = 1 << 18;

// int N, M, l, r, k, A[MAX_N], nums[MAX_N];
// vector<int> data[ST_SIZE];

// void init(int k, int l, int r) {
//     if (l + 1 == r)
//         data[k].push_back(A[l]);
//     else {
//         int lch = 2 * k + 1, rch = 2 * k + 2;
//         init(lch, l, (l + r) / 2);
//         init(rch, (l + r) / 2, r);
//         data[k].resize(r - l);
//         merge(data[lch].begin(), data[lch].end(), data[rch].begin(), data[rch].end(), data[k].begin());
//     }
// }

// int query(int a, int b, int x, int k, int l, int r) {
//     if (b <= l || r <= a)
//         return 0;
//     else
//         if (a <= l && r <= b)
//             return upper_bound(data[k].begin(), data[k].end(), x) - data[k].begin();
//         else
//             return query(a, b, x, 2 * k + 1, l, (l + r) / 2) + query(a, b, x, 2 * k + 2, (l + r) / 2, r);
// }

// int main() {
//     scanf("%d%d", &N, &M);
//     for (int i = 0; i < N; ++i) {
//         scanf("%d", A + i);
//         nums[i] = A[i];
//     }
//     sort(nums, nums + N);
//     init(0, 0, N);

//     for (int i = 0; i < M; ++i) {
//         scanf("%d%d%d", &l, &r, &k); --l;
//         int lb = -1, ub = N - 1;
//         while (lb + 1 < ub) {
//             int mid = (lb + ub) / 2;
//             if (query(l, r, nums[mid], 0, 0, N) >= k) ub = mid;
//             else lb = mid;
//         }
//         printf("%d\n", nums[ub]);
//     }

//     return 0;
// }

// const int B = 1000;

// int N, M, l, r, k;
// int A[MAX_N], nums[MAX_N];
// vector<int> bucket[MAX_N / B];

// int main(int argc, char const *argv[])
// {
//     scanf("%d%d", &N, &M);
//     for (int i = 0; i < N; ++i) {
//         scanf("%d", A + i);
//         bucket[i / B].push_back(A[i]);
//         nums[i] = A[i];
//     }
//     sort(nums, nums + N);
//     for (int i = 0; i < N / B; ++i)
//         sort(bucket[i].begin(), bucket[i].end());
//     for (int i = 0; i < M; ++i) {
//         scanf("%d%d%d", &l, &r, &k); --l;

//         int lb = -1, ub = N - 1;
//         while (lb + 1 < ub) {
//             int mid = (lb + ub) / 2;
//             int x = nums[mid];
//             int tl = l, tr = r, c = 0;

//             while (tl < tr && tl % B != 0) if (A[tl++] <= x) ++c;
//             while (tl < tr && tr % B != 0) if (A[--tr] <= x) ++c;

//             while (tl < tr) {
//                 int b = tl / B;
//                 c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
//                 tl += B;
//             }

//             if (c >= k) ub = mid;
//             else lb = mid;
//         }

//         printf("%d\n", nums[ub]);
//     }

//     return 0;
// }
