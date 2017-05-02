//可以用 Set！！！
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cfloat>
#include <queue>

using namespace std;

const int maxn = 150015;

int n, q, t[maxn], k, len, a[maxn], b[maxn];
bool flag[maxn];

void push(int x) {
    a[++len] = t[x];
    b[len] = x;
    flag[x] = true;
    int p = len;
    while (p != 1 && a[p] < a[p / 2]) {
        int tmp = a[p];
        a[p] = a[p / 2];
        a[p / 2] = tmp;
        tmp = b[p];
        b[p] = b[p / 2];
        b[p / 2] = tmp;
        p /= 2;
    }
    return ;
}
void put(int x) {
    if (t[x] > a[1] || !len) {
        flag[b[1]] = false;
        flag[x] = true;
        a[1] = t[x];
        b[1] = x;
        if (!len) len = 1;
        int fa = 1, son = 0;
        while (fa * 2 <= len) {
            if (fa * 2 + 1 > len || a[fa * 2] < a[fa * 2 + 1])
                son = fa * 2;
            else
                son = fa * 2 + 1;
            if (a[fa] > a[son]) {
                int tmp = a[fa];
                a[fa] = a[son];
                a[son] = tmp;
                tmp = b[fa];
                b[fa] = b[son];
                b[son] = tmp;
                fa = son;
            }
            else
                break;
        }
    }
    return ;
}
int main(int argc, char const *argv[])
{
    cin >> n >> k >> q;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    int tp, id;
    memset(flag, 0, sizeof(flag));
    for (int i = 1; i <= q; ++i) {
        cin >> tp >> id;
        if (tp == 1) {
            if (len < k) push(id);
            else put(id);
        }
        else {
            if (flag[id])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}