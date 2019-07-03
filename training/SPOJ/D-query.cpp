// written at 17:04 on 24 Jan 2018
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

const int maxn = 1 << 20;

struct Node{int l, r, data;};

Node Tr[maxn * 25];
int root[maxn], cnt;

int init(int l, int r) {
    int k = cnt++;
    Tr[k].data = 0;
    if (l + 1 < r) {
        Tr[k].l = init(l, (l + r) / 2);
        Tr[k].r = init((l + r) / 2, r);
    }
    return k;
}

void update(int &x, int y, int p, int l, int r, int val) {
    x = cnt++;
    Tr[x] = Tr[y];
    Tr[x].data += val;
    if (l + 1 == r) return ;
    if (p < (l + r) / 2) update(Tr[x].l, Tr[y].l, p, l, (l + r) / 2, val);
    else update(Tr[x].r, Tr[y].r, p, (l + r) / 2, r, val);
}

int query(int x, int a, int b, int l, int r) {
    if (a >= r || b <= l) return 0;
    if (a <= l && r <= b) return Tr[x].data;
    return query(Tr[x].l, a, b, l, (l + r) / 2) + query(Tr[x].r, a, b, (l + r) / 2, r);
}

int n, q, A[maxn], lst[maxn];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", A + i);
    memset(lst, -1, sizeof lst);

    init(0, n);
    for (int i = 0; i < n; i++) {
        if (lst[A[i]] != -1) {
            update(root[i + 1], root[i], lst[A[i]], 0, n, -1);
            update(root[i + 1], root[i + 1], i, 0, n, 1);
        } else update(root[i + 1], root[i], i, 0, n, 1);
        lst[A[i]] = i;
    }

    scanf("%d", &q);
    for (int i = 0, l, r; i < q; i++) {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(root[r], l - 1, n, 0, n));
    }
    return 0;
}
