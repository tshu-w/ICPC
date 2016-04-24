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

struct stop {
    int fuel, dis;
    friend bool operator< (struct stop a, struct stop b) {
        return a.dis < b.dis;
    }
};
const int maxn = 10005;
int main(void) {
    int n, l, p;
    struct stop a[maxn];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].dis >> a[i].fuel;
    cin >> l >> p;
    for (int i = 0; i < n; ++i)
        a[i].dis = l - a[i].dis;
    a[n].dis = l;
    a[n].fuel = 0;
    ++n;
    sort(a, a + n);
    priority_queue<int> que;
    int ans = 0, pos = 0, tank = p;
    for (int i = 0; i < n; ++i) {
        int d = a[i].dis - pos;
        while (tank - d < 0) {
            if (que.empty()) {
                puts("-1");
                return 0;
            }
            tank += que.top();
            que.pop();
            ans++;
        }
        tank -= d;
        pos = a[i].dis;
        que.push(a[i].fuel);
    }
    cout << ans << endl;
    return 0;
}