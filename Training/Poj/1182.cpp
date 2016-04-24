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

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;

const int maxn = 50005;
int f[3 * maxn];
int rnk[3 * maxn];

void init(int n) {
    for (int i = 0; i < n; ++i) {
        f[i] = i;
        rnk[i] = 0;
    }
}
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
int same(int x, int y) {
    return find(x) == find(y);
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) {
        f[x] = y;
    } else {
        f[y] = x;
        if (rnk[x] == rnk[y]) 
            rnk[x]++;
    }
}
int main(void) {
    int t, x, y, n, k, cnt = 0;
    scanf("%d%d", &n, &k);
    init(3 * n);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d%d", &t, &x, &y);
        --x; --y;
        if (x >= n || y >= n || x < 0 || y < 0) {
            ++cnt;
            continue;
        }
        if (t == 1) {
            if (same(x, y + n) || same(x, y + 2 * n)) {
                ++cnt;
            } else {
                unite(x, y);
                unite(x + n, y + n);
                unite(x + 2 * n, y + 2 * n);
            }
        } else {
            if (same(x , y) || same(x, y + 2 * n)) {
                ++cnt;
            } else {
                unite(x, y + n);
                unite(x + n, y + 2 * n);
                unite(x + 2 * n, y);
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
