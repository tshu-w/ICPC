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

const int maxn = 20005;
int main(void) {
    int n, l;
    ll ans = 0;
    priority_queue<int, vector<int>, greater<int> > que;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l;
        que.push(l);
    }
    while (que.size() > 1) {
        int l1, l2;
        l1 = que.top();
        que.pop();
        l2 = que.top();
        que.pop();
        ans += l1 + l2;
        que.push(l1 + l2);
    }
    cout << ans << endl;
    return 0;
}