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
const int MAX_N = 50005;
int n, a, b, c, d;

bool in(int x) {
    return ((x >= 1) && (x <= n));
}
int main(int argc, char const *argv[])
{

    ll ans = 0;
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    for (int i = 1; i <= n; ++i)
        if (in(i + a - d) && in(i + b - c) && in(i + b - c + a - d))
            ans += (ll)n;
    cout << ans << endl;
    return 0;
}