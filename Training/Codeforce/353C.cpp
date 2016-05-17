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

const int INF = INT_MAX;
const int MAX_N = 1e5 + 5;
map<ll, int> m;
int main(int argc, const char * argv[]) {
    int n, a, imax = 1;
    ll s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        s += (ll)a;
        if (m.count(s) == 0)
            m.insert(make_pair(s, 1));
        else {
            ++m[s];
            imax = max(imax, m[s]);
        }
    }
    cout << n - imax << endl;
    return 0;
}