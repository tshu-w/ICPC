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

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);

const int INF = INT_MAX;
const int MAX_N = 1e5;

int main(int argc, char const *argv[])
{
    int n, a[MAX_N];
    ll ans, sum[MAX_N];
    deque<int> d;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
        scanf("%d", &a[i]);
    d.push_front(n - 1);sum[n - 1] = ans = 1;
    for (int i = n - 2; i > 0; --i) {
        int index = upper_bound(d.begin(), d.end(), a[i]) - d.begin() - 1;
        ans += sum[i] = (ll)(n - i) + sum[d[index]] - ll(a[i] - d[index]);
        while (!d.empty() && a[i] >= a[d.front()]) d.pop_front();
        d.push_front(i);
    }
    // for (int i = 1; i < n; ++i)
    //     cout << sum[i] << " ";
    // cout << endl;
    cout << ans << endl;
    return 0;
}